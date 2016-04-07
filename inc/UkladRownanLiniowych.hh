#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include "Macierz.hh"




class UkladRownanLiniowych {
private:
    Macierz macierzWspolczynnikow;
    Wektor wektorWyrazowWolnych;
    Wektor wyniki;
    Wektor wektorBledu;
    RODZAJ_DANYCH dlogoscWektoraBledu = -3;

  public:
      void setMacierzWspolczynnikow(Macierz);
      void setWektorWyrazowWolnych(Wektor);
      Macierz& getMacierzWspolczynnikow();
      Wektor& getWektorWyrazowWolnych();
      Wektor oblicz();
      Wektor policzBlad();
      RODZAJ_DANYCH dlugoscWektoraBledu();
      void wyswietlWyniki();

};



std::istream& operator >> (std::istream&, UkladRownanLiniowych&);

std::ostream& operator << ( std::ostream&, UkladRownanLiniowych&);


#endif
