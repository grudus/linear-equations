#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>



class Macierz {
  private: Wektor tablica[ROZMIAR];

  public:
  Macierz() {
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        tablica[i] = Wektor();
    }
  }
  RODZAJ_DANYCH wyznacznik();

  // Macierz.getWektor(int ktory)
  const Wektor operator[](const unsigned int) const;
  // Macierz.setWektor(int ktory, Wektor jaki) -> macierz[1] = new Wektor()
  Wektor& operator[] (const unsigned int);
  //Zwraca dana, ktora jest w wektorze ?2 na pozycji ?1
  const RODZAJ_DANYCH operator() (const unsigned int, const unsigned int) const;

  Macierz kopia();
  // Zamienia dwa wektory miejscami
  void zamienMiejscami(const unsigned int, const unsigned int);
  void zamien(const unsigned int, const Wektor);

  Macierz transponuj();
};



std::istream& operator >> (std::istream&, Macierz&);
std::ostream& operator << (std::ostream&, const Macierz&);
Wektor operator* (const Macierz, const Wektor);


#endif
