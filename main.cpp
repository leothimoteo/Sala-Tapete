//Criar um programa que inclua retângulos em um retângulo maior
//Alunos: Cairo Martins e Leonardo Thimoteo, 07.02.2016
//Status: incompleto


//********************************************************
// C++ INCLUDES
//********************************************************
#include <cstdlib>
#include <Ponto2D.h>
#include <Retangulo.h>


//********************************************************
// protótipos de funções
//********************************************************
const int soma (const Retangulo&, const Retangulo&);

Retangulo corte (const Retangulo, const Retangulo, const int); 

Real area (const Retangulo &);

//********************************************************
// MAIN FUNCTION
//********************************************************
int main() {
    
//********************************************************
// variáveis locais
//********************************************************
Retangulo sala (10,10);
//int _soma;
//Retangulo _corte;

//Encontrando demais pontos da sala 
    std :: cout << "Pontos da sala:       "    << std :: endl;
    std :: cout << "P1= " << sala.PTR ()       << std :: endl;
    std :: cout << "P2= " << PontosRetNO(sala) << std :: endl;
    std :: cout << "P3= " << PontosRetNE(sala) << std :: endl;
    std :: cout << "P4= " << PontosRetSE(sala) << std :: endl;
    
//_______________ Testando se um ponto qualquer pertence à sala_________________
//    Ponto2D p5(-2,6);
//    
//    if (Intercep (p5, sala)) {
//        std :: cout << "está inserido\n\n\n";
//    }
//    else std :: cout << "asjndsn\n\n\n";
//    
//    Retangulo tapete (4,8,p5);    
//    _soma = soma(tapete, sala);
//    _corte = corte (tapete, sala, _soma);
//    
//    std:: cout << "Soma:" << _soma << std :: endl; 
//    std :: cout << "auhhaha : " << _corte << std :: endl;
//    
    
    
    
    
    return 0;
}


//********************************************************
// declaração de funções
//********************************************************

//__________________FUNÇÃO SOMA___________________________

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



//__________________FUNÇÃO CORTE___________________________

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

//__________________FUNÇÃO ÁREA___________________________
Real area (const Retangulo & _ret) {
    return _ret.Base() * _ret.Altura();
}