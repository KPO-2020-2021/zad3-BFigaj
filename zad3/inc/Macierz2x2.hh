#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#define MATRIX_SIZE 2

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz2x2 {
   double _Mat[MATRIX_SIZE][MATRIX_SIZE];
  public:
   Macierz2x2();
   Macierz2x2(double i);
   double operator()(int ver,int col) const {return _Mat[ver][col];}
   double& operator()(int ver,int col) {return _Mat[ver][col];}  
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

#endif
