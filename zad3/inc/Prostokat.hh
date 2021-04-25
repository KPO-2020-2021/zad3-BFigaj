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
   /*double tl[DIMIENISION];//top left point
   double tr[DIMIENISION];//top right point
   double bl[DIMIENISION];//bottom left point
   double br[DIMIENISION];//bottom right point*/
  public:
   Prostokat();
   /*double rtl(int i)const {return tl[i];}
   double rtr(int i)const {return tr[i];}
   double rbl(int i)const {return bl[i];}
   double rbr(int i)const {return br[i];}*/
   double operator [](int i) const;
   void rotacja(double i);
   void przesuniecie(Wektor2D vec);
   void przesunieciewektor(Wektor2D vec);
   //double operator *(Wektor2D vec, Macierz2x2 mtx);
   
 
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
//std::ostream& operator << (std::ostream &Strm,const Prostokat &Pr);
std::ostream& operator << (std::ostream &Strm,const Prostokat &Pr);
bool filesave(const char *filename,const Prostokat &Pr );

#endif
