#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Wektor2D.hh"
#define DL_BOK 150
#define KR_BOK 100
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat {
   Macierz2x2 mtx;
   Wektor2D tl;
   Wektor2D tr;
   Wektor2D bl;
   Wektor2D br;
   double bok1=DL_BOK;
   double bok2=KR_BOK;
   double bok3=DL_BOK;
   double bok4=KR_BOK;
   
  public:
   Prostokat();
   Prostokat(double x,double y);
   /*double rtl(int i)const {return tl[i];}
   double rtr(int i)const {return tr[i];}
   double rbl(int i)const {return bl[i];}
   double rbr(int i)const {return br[i];}*/
   double operator [](int i) const;
   void rotacja(double i);
   void przesuniecie(Wektor2D vec);
   void przesunieciewektor(Wektor2D vec);
   bool sprawdzeniebok() const;
   //double operator *(Wektor2D vec, Macierz2x2 mtx);
   
 
};


/*
 * To przeciazenie operatora sluzy do wypisywania prostokata
 * Przyjmuje dane:
 * -std::ostream &Strm-dana okreslajaca typ strumienia wyjsciowego (np. cout)
 * -const Prostokat &Pr- wskaznik na prostokat ktory chcemy wypisac
 * Funkcja wypisuje wspolrzedne punktow z prostokata
 */

std::ostream& operator << (std::ostream &Strm,const Prostokat &Pr);
bool filesave(const char *filename,const Prostokat &Pr );

#endif
