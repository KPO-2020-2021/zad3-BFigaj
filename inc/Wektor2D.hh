#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include "Macierz2x2.hh"
#define ROZMIAR_WEKTORA 2

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor2D {
   double _Wsp[ROZMIAR_WEKTORA];  
  public:
   Wektor2D(){_Wsp[0]=_Wsp[1]=0;}
   Wektor2D(double x, double y){_Wsp[0]=x; _Wsp[1]=y;}
   double operator [](int index) const {return _Wsp[index];}
   double& operator [](int index) {return _Wsp[index];}
   Wektor2D operator+ (Wektor2D vec) const;
   Wektor2D operator- (Wektor2D vec) const;
   Wektor2D& operator* (Macierz2x2 mtx);
   bool operator== (Wektor2D vec) const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);



#endif
