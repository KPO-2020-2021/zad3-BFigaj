#include "Macierz2x2.hh"
#include <iostream>
#include <math.h>
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz2x2, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Macierz2x2::Macierz2x2()
{
    _Mat[0][0]=cos(0);
    _Mat[0][1]=-sin(0);
    _Mat[1][0]=sin(0);
    _Mat[1][1]=cos(0);
}

Macierz2x2::Macierz2x2(double i)
{
    double katrad;
    katrad=(i*M_PI)/180;
    _Mat[0][0]=cos(katrad);
    _Mat[0][1]=-sin(katrad);
    _Mat[1][0]=sin(katrad);
    _Mat[1][1]=cos(katrad);
}
double Macierz2x2::det()const
{
        return (this->_Mat[0][0]*this->_Mat[1][1])-(this->_Mat[0][1]*this->_Mat[1][0]);
}
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac)
{
    Strm <<"|" << Mac(0,0) <<" " << Mac(0,1) << "|" << std::endl;
    Strm <<"|" << Mac(1,0) <<" " << Mac(1,1) << "|" << std::endl;
    return Strm;
}
