#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  private: RODZAJ_DANYCH dane[ROZMIAR];
  public:
  //Konstruktor domyslny wypelnia wszystko zerami.
   Wektor() {
        int i;
        for (i = 0; i < ROZMIAR; i++) dane[i] = 0;
   }

   Wektor dodaj(Wektor);
   Wektor odejmij(Wektor);
   RODZAJ_DANYCH iloczynSkalarny(Wektor);
   Wektor pomnoz(RODZAJ_DANYCH);
   Wektor podziel(RODZAJ_DANYCH);
   void setDane(const unsigned int, ...);
   void setDane(RODZAJ_DANYCH*);
   const RODZAJ_DANYCH operator[] (const unsigned int) const;
   RODZAJ_DANYCH& operator[] (const unsigned int);
   

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
