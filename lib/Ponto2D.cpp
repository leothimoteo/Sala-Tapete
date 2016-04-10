#include <Ponto2D.h>
#include <iostream>


std :: ostream& operator << (std :: ostream& _os, const Ponto2D& _ponto){
    _os << "(" <<  _ponto.x << "," << _ponto.y << ")";
    return _os;
}
    const Ponto2D& Ponto2D:: operator= (const Ponto2D& _ponto){
        if (this != &_ponto){
            x = _ponto.x;
            y = _ponto.y;
        }
        return *this;
    }
    
    const bool Ponto2D :: operator== (const Ponto2D &_pt) const 
{
    return x==_pt.x && y== _pt.y; 
}
    
std :: istream& operator >> (std :: istream& _os,  Ponto2D& _pt){
    	_os >> _pt.x >> _pt.y;
	return _os;
}


