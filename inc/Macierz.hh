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
  const Wektor operator[](const unsigned int) const;
  Wektor& operator[] (const unsigned int i) {return tablica[i];}
   
  const RODZAJ_DANYCH operator() (const unsigned int x, const unsigned int y) const {
	return tablica[y][x];
} 

};



//std::istream& operator >> (std::istream &Strm, Macierz &Mac);

std::ostream& operator << (std::ostream&, Macierz&);


#endif
