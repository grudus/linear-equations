#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

/**
    @author Kuba Gruda
    @date 18.04.2016
    @version 1.0

    @file
    @brief Definicja klasy UkladRownanLiniowych

    Cala logika programu
 */

#include "Macierz.hh"



/**
    @brief Wlasciwa klasa

    Przechowuje wszystkie wartosci wartosci niezbedne do rozwiazania ukladu rownan liniowych:
    macierz wspolczynnikow, wektor wyrazow wolnych, wektor wynikow i wiadomosci o bledach obliczen.
 */
class UkladRownanLiniowych {
private:
    /**
        @brief Macierz wspolczynnikow

        Przechowuje wspolczynniki przy zmiennych z podanego rownania
     */
    Macierz macierzWspolczynnikow;
    /**
        @brief Wektor wyrazow wolnych

        Przechowuje wartosci wyrazow wolnych
     */
    Wektor wektorWyrazowWolnych;
    /**
        @brief Wektor wynikow

        Zostanie wypelniony po wykonaniu metody <code>oblicz</code>
     */
    Wektor wyniki;
    /**
        @brief Wektor bledow

        Zostanie wypelniony po wykonaniu metody <code>policzBlad</code>
     */
    Wektor wektorBledu;
    /**
        @brief dlugosc wektora bledu

        Zostanie wypelniony po wykonaniu metody <code>dlugoscWektoraBledu</code>
     */
    RODZAJ_DANYCH dlogoscWektoraBledu;

  public:
      /**
        @brief Setter dla macierzy wspolczynnikow

        Ustawia wartosc pola <code>macierzWspolczynnikow</code>

        @param m Macierz wspolczynnikow
       */
      void setMacierzWspolczynnikow(Macierz m);
      /**
        @brief Setter dla wektoru wyrazow wolnych

        Ustawia wartosc pola <code>wektorWyrazowWolnych</code>

        @param w Wektor wyrazow wolnych
       */
      void setWektorWyrazowWolnych(Wektor w);
      /**
        @brief Getter dla macierzy wspolczynnikow

        Pobiera wartosc pola <code>macierzWspolczynnikow</code>

        @return Macierz wspolczynnikow
       */
      Macierz& getMacierzWspolczynnikow();
      /**
        @brief Getter dla wektora wyrazow wolnych

        Pobiera wartosc pola <code>wektorWyrazowWolnych</code>

        @return Wektor wyrazow wolnych
       */
      Wektor& getWektorWyrazowWolnych();
      /**
        @brief Obliczenie pierwiastkow rownania

        Najwazniejsza metoda programu. Oblicza wyniki ukladu rownan.
        Wykorzystuje do tego metode Crammera - liczy wyznaczniki (metoda Gaussa)
        poszczegolnych zmiennych i dzieli przez wyznacznik glowny.

        @return Wektor wynikow
      */
      Wektor oblicz();
      /**
        @brief Obliczenie bledu

        Liczenie bledu polegajacego na niedokladnosci obliczen komputerowych.

        @return Wektor bledu
       */
      Wektor policzBlad();
      /**
        @brief Obliczanie dlugosc wektora bledu

        Liczone na prawach matematycznych.

        @return Dlugosc wektora bledu
       */
      RODZAJ_DANYCH dlugoscWektoraBledu();
      /**
        @brief Wyswietlanie wyniku

        Metoda typu <code>toString</code>. Ladnie wyswietla wyniki.
       */
      void wyswietlWyniki();

};



std::istream& operator >> (std::istream&, UkladRownanLiniowych&);

std::ostream& operator << ( std::ostream&, UkladRownanLiniowych&);


#endif
