
#include <Retangulo.h>
#include <Ponto2D.h>
#include <iostream>
#include <math.h>

std :: ostream& operator << (std :: ostream& _os, const Retangulo& _ret){
    _os << "Base: " << _ret.base << 
             "  Altura: " << _ret.altura << 
               "  coord: " << _ret.ptr; 
    return _os; 
    
}

const Retangulo& Retangulo:: operator= (const Retangulo& _ret) {
    if (this != &_ret){
        base = _ret.base;
        altura = _ret.altura;
        ptr = _ret.ptr;
    }
    
    return *this;
}

 std :: istream &operator >> (std :: istream&_os,  Retangulo &_ret){
	_os >> _ret.base >> _ret.altura >> _ret.ptr;
	return _os;
}

//==============================================================================
//               função que calcula demais pontos do retângulo
//==============================================================================
   const Ponto2D PontosRetNO (const Retangulo& _ret) {    //ponto noroeste
       return Ponto2D ( _ret.PTR().X() , _ret.PTR().Y() + _ret.altura);       
   }
   
   const Ponto2D PontosRetNE (const Retangulo& _ret) {    //ponto nordeste
       return Ponto2D ( _ret.PTR().X() + _ret.base, _ret.PTR().Y() + _ret.altura);       
   }
   
   const Ponto2D PontosRetSE (const Retangulo& _ret) {    //ponto sudeste
       return Ponto2D ( _ret.PTR().X() + _ret.base, _ret.PTR().Y());       
   }
   
 
//==============================================================================
//                           função de interseção
//==============================================================================
       const bool Intercep (const Ponto2D& _pt, const Retangulo& _ret) {
                    
           //ponto qualquer do tapete e um ponto da sala
           return ((_ret.PTR().X() < _pt.X() && _pt.X() < (PontosRetSE(_ret)).X())&&
                   (_ret.PTR().Y() < _pt.Y() && _pt.Y() < (PontosRetNO(_ret)).Y()));
               
        }