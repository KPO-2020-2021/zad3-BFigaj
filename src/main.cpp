#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150

int main()
{
  int ile,i;
  double kat;
  char wybor[2]=" ";
  Wektor2D W1,W2;
  Prostokat             Pr;   // To tylko przykladowe definicje zmiennej
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);
  while(wybor[0]!='e')/*Warunek zakonczenia programu*/
   {
       if (!filesave("prostokat.dat",Pr)) return 1;
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       Pr.sprawdzeniebok();
       cout << "Twoj wybor (m-menu) -";
       cin >> wybor;
       switch(wybor[0])
       {
            case 'm':cout << "m - wyswietlenie menu" << endl 
                     << "o - obrot prostokata o zadany kat" << endl
                     << "p - przesuniecie  o zadany wektor" << endl
                     << "w - wyswietlenie wspolrzednych wierzcholkow" << endl
                     << "e - exit" << endl;
                     break;
            case 'p':cout << "Wpisz wspolrzedne wectora " << endl;
                     cin >> W1;
                     Pr.przesunieciewektor(W1);
                     break;
            case 'o':cout << "Ile razy ma sie dokonac operacja " << endl;
                     cin >> ile;
            cout << "Podaj kat" << endl;
                     cin >> kat;
                     for(i=1;i<=ile;++i)
                            Pr.rotacja(kat);
                     break;
            case 'w':cout << Pr;
                     break;
            case 'b':break;
            case 'e':break;
            default:cerr << "Nie poprawny wybor opcji";break;
       }
    }
  



}
