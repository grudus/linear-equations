#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  RODZAJ_DANYCH dane[ROZMIAR];
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
   Wektor(RODZAJ_DANYCH d1 = 0, RODZAJ_DANYCH d2 = 0, RODZAJ_DANYCH d3= 0) {
        dane[0] = d1;
        dane[1] = d2;
        dane[2] = d3;
   }
   Wektor dodaj(Wektor);
   Wektor odejmij(Wektor);
   RODZAJ_DANYCH iloczynSkalarny(Wektor);
   Wektor pomnoz(RODZAJ_DANYCH);
   Wektor podziel(RODZAJ_DANYCH);
   void setDane(RODZAJ_DANYCH, RODZAJ_DANYCH, RODZAJ_DANYCH);
   RODZAJ_DANYCH operator[] (unsigned int);

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream&, Wektor&);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream&, /*const*/  Wektor&);

Wektor operator+(Wektor, Wektor);
Wektor operator-(Wektor, Wektor);
RODZAJ_DANYCH operator*(Wektor, Wektor);
Wektor operator*(Wektor, RODZAJ_DANYCH);
Wektor operator/(Wektor, RODZAJ_DANYCH);



#endif
