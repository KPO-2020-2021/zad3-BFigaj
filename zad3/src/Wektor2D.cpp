#include "Wektor2D.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor2D, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Wektor2D Wektor2D::operator+ (Wektor2D vec) const
{
    Wektor2D newvec;
    newvec._Wsp[0]=vec._Wsp[0]+this->_Wsp[0];
    newvec._Wsp[1]=vec._Wsp[1]+this->_Wsp[1];
    return newvec;
}

Wektor2D Wektor2D::operator- (Wektor2D vec) const
{
    Wektor2D newvec;
    newvec._Wsp[0]=this->_Wsp[0]-vec._Wsp[0];
    newvec._Wsp[1]=this->_Wsp[1]-vec._Wsp[1];
    return newvec;
}
Wektor2D& Wektor2D::operator* (Macierz2x2 mtx)
{
    Wektor2D vec;
    vec=*this;
    //std::cout << *this;
    //std::cout << (vec._Wsp[0])*(mtx(0,0))<< std::endl;
    //std::cout << (vec._Wsp[0])*(mtx(0,1))<< std::endl;
    //vec._Wsp[0]=(this->_Wsp[0]*mtx(0,0))+(this->_Wsp[1]*mtx(0,1));
    //vec._Wsp[1]=(this->_Wsp[0]*mtx(1,0))+(this->_Wsp[1]*mtx(1,1));
    this->_Wsp[0]=((vec._Wsp[0])*(mtx(0,0)))+((vec._Wsp[1])*(mtx(0,1)));
    //std::cout << *this;
    this->_Wsp[1]=((vec._Wsp[0])*(mtx(1,0)))+((vec._Wsp[1])*(mtx(1,1)));
    //std::cout << *this;
    return *this;
}

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
    double x,y;
    Strm >> x >> y;
    Wek[0]=x;
    Wek[1]=y;
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek)
{
    Strm << "[" << Wek[0] << "," << Wek[1] << "]" << std::endl;
    return Strm;
}