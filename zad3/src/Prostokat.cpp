#include <iostream>
#include <iomanip>
#include <fstream>
#include "Prostokat.hh"

using namespace std;
/*
 *  Funkcja inicjujaca prostokat
 */
Prostokat::Prostokat()
{
    double x,y;
    x=y=10;
    tl[0]=x;
    tl[1]=y+KR_BOK;
    tr[0]=x+DL_BOK;
    tr[1]=y+KR_BOK;
    bl[0]=x;
    bl[1]=y;
    br[0]=x+DL_BOK;
    br[1]=y;

}
/*
 *  Funkcja przeciazenia operatora []
 *  przyjmuje dane:
 *  -int i - jako index sluzacy do wybrania dokladnego elementu prostokata
 *  odsyla:
 *  -skladowa x lub y wybranego punktu z prostokata (jako liczbe typu double)
 */
double Prostokat::operator[](int i)const
{
     if(i==0)//wartosc i rowna 1 odeslij x skadowa punktu tl
     {
          return tl[0];
     }
     if(i==1)//wartosc i rowna 1 odeslij y skadowa punktu tl
     {
          return tl[1];
     }
     if(i==2)//wartosc i rowna 1 odeslij x skadowa punktu tr
     {
          return tr[0];
     }
     if(i==3)//wartosc i rowna 1 odeslij y skadowa punktu tr
     {
          return tr[1];
     }
     if(i==4)//wartosc i rowna 1 odeslij x skadowa punktu br
     {
          return br[0];
     }
     if(i==5)//wartosc i rowna 1 odeslij y skadowa punktu br
     {
          return br[1];
     }
     if(i==6)//wartosc i rowna 1 odeslij x skadowa punktu bl
     {
          return bl[0];
     }
     if(i==7)//wartosc i rowna 1 odeslij y skadowa punktu bl
     {
          return bl[1];
     }
     std::cerr << "Niepoprawna wartosc funkcji operatora []" << std::endl;
     return 0;
}
/*
 *  Funkcja realizujaca rotacje prostokata o zadany kat
 *  przyjmuje dane:
 *  -int i - jako index sluzacy do wybrania dokladnego elementu prostokata
 */
void Prostokat::rotacja(double i)
{
     Macierz2x2 mtx(i);
     tl=tl*mtx;
     tr=tr*mtx;
     br=br*mtx;
     bl=bl*mtx;
}
/*
 *  Funkcja realizujaca przesuniecie prostokata o wektor
 *  przyjmuje dane:
 *  -Wektor2D vec - przyjmuje wektor by przesunac prostokat 
 */
void Prostokat::przesunieciewektor(Wektor2D vec)
{
     this->tl=vec+this->tl;
     this->tr=vec+this->tr;
     this->br=vec+this->br;
     this->bl=vec+this->bl;
}

std::ostream& operator <<(std::ostream &Strm,const Prostokat &Pr) 
{
  Strm << setw(16) << fixed << setprecision(10) << Pr[0]
       << setw(16) << fixed << setprecision(10) << Pr[1] << endl;
  Strm << setw(16) << fixed << setprecision(10) << Pr[2]
       << setw(16) << fixed << setprecision(10) << Pr[3] << endl;
  Strm << setw(16) << fixed << setprecision(10) << Pr[4] 
       << setw(16) << fixed << setprecision(10) << Pr[5] << endl;
  Strm << setw(16) << fixed << setprecision(10) << Pr[6] 
       << setw(16) << fixed << setprecision(10) << Pr[7] << endl;
  Strm << setw(16) << fixed << setprecision(10) << Pr[0]
       << setw(16) << fixed << setprecision(10) << Pr[1] << endl;
  return Strm;
}
/*
 *  Funkcja realizujaca przesuniecie prostokata o wektor
 *  przyjmuje dane:
 *  -const char* filename - wskaznik na napis ktory sluzy jako nazwa pliku
 *  -const Prostokat &Pr - referencja do zmiennej typu Prostokat 
 *  odsyla:
 *  -false jesli operacja zabisu sie powiodla 
 *  -true jesli sie powiodla
 */
bool filesave(const char *filename,const Prostokat &Pr )
{
  ofstream  filestrm;

  filestrm.open(filename);
  if (!filestrm.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  filestrm << Pr;

  filestrm.close();
  return !filestrm.fail();
}