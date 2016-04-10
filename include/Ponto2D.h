
#ifndef PONTO2D_H
#define PONTO2D_H

//==============================================================================
//                              INCLUDE C++
//============================================================================== 
#include <iostream>

//==============================================================================
//                                typedef
//============================================================================== 
typedef double         Real;        //real é sinônimo de double


class Ponto2D {
    
public:
    
//==============================================================================
//                             função friend
//==============================================================================
    
    friend std :: ostream& operator << (std :: ostream&, const Ponto2D&);
    friend std :: istream& operator >> (std :: istream&,  Ponto2D&);  
    
//==============================================================================
//                       CONSTRUTORES E DESTRUTORA
//============================================================================== 
    
    Ponto2D(): x(0), y(0) {};                                    //construtor default
    Ponto2D(const Ponto2D& _orig) : x(_orig.x), y(_orig.y) {};   //cópia
    Ponto2D (const Real &_x, const Real &_y): x(_x), y(_y) {};   //específica
    virtual ~Ponto2D() {};                                       //destrutor
    
    
//==============================================================================
//                        SOBRECARGA DE OPERADORES
//============================================================================== 
    
    const Ponto2D& operator= (const Ponto2D&);
    const bool operator== (const Ponto2D &) const;
    
//==============================================================================
//                              FUNÇÕES INLINE
//============================================================================== 
    
    inline  const Real X() const {return x;}; //exibir apenas abscissa
    inline  const Real Y() const {return y;}; //exibir apenas ordenada
 
protected:

    Real x, y;    //parâmetros que definem ponto 2D
};

#endif /* PONTO2D_H */

