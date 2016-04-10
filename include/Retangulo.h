
#ifndef RETANGULO_H
#define RETANGULO_H


//==============================================================================
//                               INCLUDE C++
//============================================================================== 
#include <iostream>


//==============================================================================
//                            INCLUDE da classe
//============================================================================== 
#include <Ponto2D.h>


class Retangulo : protected Ponto2D {
    
//==============================================================================
//                            funções friend
//============================================================================== 
    friend std :: ostream& operator << (std :: ostream&, const Retangulo&);
    friend std :: istream& operator >> (std :: istream&,  Retangulo&);   
    
//Encontrar demais pontos do retângulo 
    friend const Ponto2D PontosRetNO (const Retangulo&);   //ponto noroeste
    friend const Ponto2D PontosRetNE (const Retangulo&);   //ponto nordeste
    friend const Ponto2D PontosRetSE (const Retangulo&);   //ponto sudeste

    
//função interceptar
    friend const bool Intercep (const Ponto2D&, const Retangulo&);
        

public:
    
//==============================================================================
//                         CONSTRUTORES E DESTRUTORA
//============================================================================== 
    
    Retangulo() : base(0), altura (0), ptr() {};                                 // construtora default
    Retangulo (const Real& _base, const Real &_altura, const Ponto2D& _pto):     // construtora específica
            base (_base), altura (_altura), ptr (_pto) {};
            
    Retangulo(const Retangulo& _orig) : base(_orig.base), altura (_orig.altura), // construtora de cópia
            ptr (_orig.ptr) {};
    
    Retangulo (const Real _base, const Real _altura) : base(_base),             // construtora específica
  
            altura (_altura), ptr() {};
            
    Retangulo (const Real _base, const Real _altura, const Real _x, const Real _y) :
    base(_base), altura (_altura), ptr (_x, _y) {};
            
    virtual ~Retangulo() {};                                                     // destrutora
    
//==============================================================================
//                        SOBRECARGA DE OPERADORES
//============================================================================== 
    
    const Retangulo& operator= (const Retangulo&);
    const bool operator== (const Retangulo &) const;

    
//==============================================================================
//                            FUNÇÕES INLINE
//==============================================================================
    
    inline  const Real Base() const {return base;};
    inline  const Real Altura() const {return altura;};
    inline  const Ponto2D PTR () const {return ptr;};
    

    
//==============================================================================
//                           VARIÁVEIS PRIVADAS
//==============================================================================    
    
private:

    Real base, altura;
    Ponto2D ptr; //posição no espaço -> sudoeste
    

};

#endif /* RETANGULO_H */

