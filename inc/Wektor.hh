#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


class Wektor {
  private: RODZAJ_DANYCH dane[ROZMIAR];
  public:
  //Konstruktor domyslny wypelnia wszystko zerami.
   Wektor() {
        int i;
        for (i = 0; i < ROZMIAR; i++) dane[i] = 0;
   }

   Wektor dodaj(const Wektor);
   Wektor odejmij(const Wektor);
   RODZAJ_DANYCH iloczynSkalarny(const Wektor);
   Wektor pomnoz(const RODZAJ_DANYCH);
   Wektor podziel(const RODZAJ_DANYCH);
   void zamienMiejscami(const unsigned int, const unsigned int);
   const RODZAJ_DANYCH operator[] (const unsigned int) const;
   RODZAJ_DANYCH& operator[] (const unsigned int);
   Wektor kopia();



};


/* ***** Przeciazenia operatorow ****** */
std::istream& operator >> (std::istream&, Wektor&);
std::ostream& operator << (std::ostream&, const  Wektor&);
Wektor operator+(Wektor, Wektor);
Wektor operator-(Wektor, Wektor);
RODZAJ_DANYCH operator*(Wektor, Wektor);
Wektor operator*(Wektor, RODZAJ_DANYCH);
Wektor operator/(Wektor, RODZAJ_DANYCH);



#endif
