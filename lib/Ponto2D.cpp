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
    
std :: istream& operator >> (std :: istream& _os,  Ponto2D& _pt){
    	_os >> _pt.x >> _pt.y;
	return _os;
}


