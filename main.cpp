//Criar um programa que inclua retângulos em um retângulo maior
//Alunos: Cairo Martins e Leonardo Thimoteo, 07.02.2016
//Status: Completo


//******************************************************************************
//                               C++ INCLUDES
//******************************************************************************
#include <cstdlib>
#include <Ponto2D.h>
#include <Retangulo.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>


//******************************************************************************
//                          protótipos de funções
//******************************************************************************
const int soma (const Retangulo&, const Retangulo&);

Retangulo corte (const Retangulo, const Retangulo, const int); 

Real area (const Retangulo &);

//******************************************************************************
//                                typedef
//******************************************************************************
    typedef std :: list <Retangulo>                LstRet;
    typedef LstRet :: iterator                     ItLstRet;
    


//******************************************************************************
//                             MAIN FUNCTION
//******************************************************************************
int main() {
    
// ************************* variáveis locais **********************************
Retangulo sala (10,10), R1;
int _soma;
int i(1);
Retangulo _corte;
Real _area(0), adsct(0);    // adsct armazena área comum entre dois tapetes


//______________ Encontrando demais pontos da sala______________________________

    std :: cout << "Pontos da sala:       "    << std :: endl;
    std :: cout << "P1= " << sala.PTR ()       << std :: endl;
    std :: cout << "P2= " << PontosRetNO(sala) << std :: endl;
    std :: cout << "P3= " << PontosRetNE(sala) << std :: endl;
    std :: cout << "P4= " << PontosRetSE(sala) << "\n"<< std :: endl;
    
    
// ********************** declarando lista e iterator **************************
    LstRet    lista, lista_corte;
    ItLstRet  it_lista (lista.begin());  
    
    
    
//******************** importando arquivo externo*******************************
    
    std :: ifstream input("tapetes_previos.txt"); //PRECISA EXISTIR
        
//____________________________TESTE EXISTÊNCIA _________________________________
    
    if (!input){
        std :: cerr << "Arquivo inexistente" << std :: endl;
        abort ();
    }

//____________________________importando dados e________________________________    
//_____________escrevendo tapetes cortados em uma lista_________________________
    
    while (!input.eof()){
         input >> R1;
         std :: cout << "Tapete "<<i<<": "<< R1 << std :: endl;
         _soma = soma (R1, sala);
         std :: cout << "Soma: " << _soma << std :: endl;
         _corte = corte (R1, sala, _soma);
         std :: cout << "Retângulo cortado: " << _corte << "\n" <<std :: endl; 
         lista.push_front(_corte);
         i++;
    }
    
    input.close ();
    
    /*O método faz com que o último elemento do arquivo externo seja duplicado 
     na lista. Portanto, ao enviá-los para a lista, o elemento duplicado, que 
     se encontra na primeira posição, é apagado */
    
//_______________________apagando elemento repetido_____________________________
    
   ItLstRet it_fim(lista.begin());       //iterador
   advance (it_fim,1);                   //aponta para o segundo endereço da lista
   lista.erase (lista.begin (), it_fim); //apaga elemento repetido
  
   
   std :: cout << "\n";
   
//___________________cortando tapetes interceptados_____________________________
   
   int m=0;
   Retangulo *x;
   x=new Retangulo [lista.size()];   //cria vetor com dimensão da lista
   
//_________________________imprimindo lista_____________________________________  
   
    for (it_lista =lista.begin(); it_lista !=lista.end(); it_lista++){
        std :: cout << "elemento: " << *it_lista << std::endl;
        x[m]=*it_lista;
        m++;
    }
   
   std :: cout << "\n";
   
//_______________enviando áreas de interseção para lista________________________
   
   for (int i=0; i< lista.size(); i++) {
       for (int n=0; n<lista.size(); n++){
           if (i<=n){
               n++;    //evita repetição entre tapetes
           }
           
           else {
           _soma= soma(x[n], x[i]);
           std :: cout << "Soma: " << _soma << std :: endl;
           _corte=corte (x[n], x[i], _soma);
           lista_corte.push_front(_corte);
           
            }
     }
   }  
   
//_________________Imprimindo lista de retângulos eliminados____________________
   
   std:: cout << "\n\nImprimindo lista de corte: " << std :: endl;
  
    for (it_lista =lista_corte.begin(); it_lista !=lista_corte.end(); it_lista++){
        std :: cout << *it_lista <<std::endl;
    }   

//__________________________Calculando áreas____________________________________
   
   //********************* área total dos tapetes ******************************
   for (int i=0; i< lista.size(); i++){
       _area+= area (x[i]);
   }
   
   //********************* área útil dos tapetes *******************************
    it_lista =lista_corte.begin();
   
      for (int i=0; i< lista.size(); i++){
       adsct+= area (*it_lista);
       it_lista++;
   }
    
 //________________________Exibindo resultados__________________________________
   std :: cout << "\n";   
   std :: cout << "Área da sala: " << area (sala) << " m2" <<std :: endl;
   std :: cout << "Área dos tapetes: " << _area << " m2" << std :: endl;
   std :: cout << "Área útil dos tapetes: " << _area - adsct << " m2" << std :: endl;
 

    

//_______________ Testando se um ponto qualquer pertence à sala_________________
//    Ponto2D p5(-2,6);
//    
//    if (Intercep (p5, sala)) {
//        std :: cout << "está inserido\n\n\n";
//    }
//    else std :: cout << "não está inserido\n\n";
//    
//    Retangulo tapete (4,8,p5);    
//    _soma = soma(tapete, sala);
//    _corte = corte (tapete, sala, _soma);
//    
//    std:: cout << "Soma:" << _soma << std :: endl; 
//    std :: cout << "área de interseção: " << _corte << std :: endl;
//    
    
    
    return 0;
}


//********************************************************
// declaração de funções
//********************************************************

//__________________1. FUNÇÃO SOMA___________________________

const int soma (const Retangulo&_ret, const Retangulo &_abc) {
    
    int soma;

    soma= (1*Intercep(_ret.PTR(), _abc) + 2*(Intercep(PontosRetNO(_ret), _abc)) + 
                4*(Intercep(PontosRetNE(_ret), _abc)) + 8*(Intercep (PontosRetSE(_ret), _abc)));
    
    if (soma==0) {
 
        
        if ((_abc.PTR().Y() < _ret.PTR().Y() && _ret.PTR().Y() < PontosRetNO(_abc).Y()) &&   //tapete transversal horizontal
                (_abc.PTR().X() > _ret.PTR().X() && PontosRetSE(_ret).X() > PontosRetSE(_abc).X())) {
            
            soma=16;
        }
        
    
        else if ((_abc.PTR().X() < _ret.PTR().X() && _ret.PTR().X() < PontosRetSE(_abc).X()) &&    //tapete transversal vertical
                (_abc.PTR().Y() > _ret.PTR().Y() && PontosRetNO(_ret).Y() > PontosRetNO(_abc).Y())) {
            
            soma=17;
        }
    
        else if ((1*Intercep(_abc.PTR(), _ret) + 2*(Intercep(PontosRetNO(_abc), _ret)) +  //tapete maior que sala
                      4*(Intercep(PontosRetNE(_abc), _ret)) + 8*(Intercep (PontosRetSE(_abc), _ret))) == 15){
            
            soma=18;
        }
    
        else  soma=19;  //tapete e sala externos
    
    }
        return soma; 
}   
/*    A soma diz respeito AO TAPETE, não à sala */

//____________________________2. FUNÇÃO CORTE___________________________________

Retangulo corte (const Retangulo _ret, const Retangulo _abc, const int _num){ //abc -> sala
    
    switch (_num) {
        
        case 1:
            return Retangulo (((PontosRetSE (_abc)).X() - _ret.PTR().X()), 
                    ((PontosRetNE(_abc)).Y() - _ret.PTR().Y()),
                    _ret.PTR());
            break;
            
            
        case 2:
            return Retangulo (((PontosRetSE (_abc)).X() - _ret.PTR().X()), 
                    ((PontosRetNE(_ret)).Y() - _abc.PTR().Y()), 
                    _ret.PTR().X(), _abc.PTR().Y());
            break;
            
        
        case 3:
            return Retangulo (PontosRetSE(_abc).X() - _ret.PTR().X(),
                    _ret.Altura(), 
                    _ret.PTR());
            break;
            
            
        case 4:
            return Retangulo ((PontosRetNE(_ret).X() - _abc.PTR().X()), 
                    (PontosRetNE(_ret).Y() - _abc.PTR().Y()), 
                    _abc.PTR());
            break;
            
            
        case 6: 
            return Retangulo (_ret.Base(), 
                    PontosRetNO(_ret).Y() - _abc.PTR().Y(), 
                    _ret.PTR().X(), _abc.PTR().Y());
            break;
            
            
        case 8:
            return Retangulo (PontosRetNE(_ret).X() - _abc.PTR().X(),
                    _ret.Altura() - (PontosRetNO(_ret).Y() - PontosRetNO(_abc).Y()), 
                    _abc.PTR().X(), _ret.PTR().Y());
            break;
                        
        case 9:
            return Retangulo (_ret.Base(),
                    PontosRetNO(_abc).Y() - _ret.PTR().Y(), 
                    _ret.PTR());
            break;
            
            
        case 12:
            return Retangulo (PontosRetSE(_ret).X() - _abc.PTR().X(),
                   _ret.Altura(), 
                   _abc.PTR().X(), _ret.PTR().Y());
            break;
            
        case 15: 
            return _ret;  //tapete inteiramente dentro da sala
            break;
        
        case 16: 
            return Retangulo (_abc.Base(),    //tapete transversal horizontal
                    _ret.Altura(),
                    _abc.PTR().X(), _ret.PTR().Y());
            break;
            
        case 17:
            return Retangulo (_ret.Base(),          //tapete transversal vertical
                    _abc.Altura(),
                    _ret.PTR().X(), _abc.PTR().Y());
            break;
            
        case 18:
            return _abc; //tapete maior que a sala
            break; 
        
        default:
            return Retangulo (); //tapete externo à sala
            break;
    }
}

//__________________________3. FUNÇÃO ÁREA______________________________________
Real area (const Retangulo & _ret) {
    return _ret.Base() * _ret.Altura();
}