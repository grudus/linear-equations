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

  void setDane(Wektor*);
  Wektor operator[](unsigned int);

};



//std::istream& operator >> (std::istream &Strm, Macierz &Mac);

std::ostream& operator << (std::ostream&, Macierz&);


#endif
