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
template <typename T>
class UkladRownanLiniowych {
private:
    unsigned int rozmiar;
    /**
        @brief Macierz wspolczynnikow

        Przechowuje wspolczynniki przy zmiennych z podanego rownania
     */
    Macierz<T> macierzWspolczynnikow;
    /**
        @brief Wektor wyrazow wolnych

        Przechowuje wartosci wyrazow wolnych
     */
    Wektor<T> wektorWyrazowWolnych;
    /**
        @brief Wektor wynikow

        Zostanie wypelniony po wykonaniu metody <code>oblicz</code>
     */
    Wektor<T> wyniki;
    /**
        @brief Wektor bledow

        Zostanie wypelniony po wykonaniu metody <code>policzBlad</code>
     */
    Wektor<T> wektorBledu;
    /**
        @brief dlugosc wektora bledu

        Zostanie wypelniony po wykonaniu metody <code>dlugoscWektoraBledu</code>
     */
    T dlogoscWektoraBledu;

  public:
      UkladRownanLiniowych() {
      	rozmiar = ROZMIAR;
      	  wektorBledu = Wektor<T>(rozmiar);
          macierzWspolczynnikow = Macierz<T>(rozmiar);
          wektorWyrazowWolnych = Wektor<T>(rozmiar);
          wyniki = Wektor<T>(rozmiar);
      }

      UkladRownanLiniowych(unsigned int rozm) {
          rozmiar = rozm;
          wektorBledu = Wektor<T>(rozmiar);
          macierzWspolczynnikow = Macierz<T>(rozmiar);
          wektorWyrazowWolnych = Wektor<T>(rozmiar);
          wyniki = Wektor<T>(rozmiar);

      }

      unsigned int getRozmiar() const {return rozmiar;}


      /**
        @brief Setter dla macierzy wspolczynnikow

        Ustawia wartosc pola <code>macierzWspolczynnikow</code>

        @param m Macierz wspolczynnikow */
        
      void setMacierzWspolczynnikow(Macierz<T>& m) {
      		macierzWspolczynnikow = m;
   	  }
   	  
   	  
      /**
        @brief Setter dla wektoru wyrazow wolnych

        Ustawia wartosc pola <code>wektorWyrazowWolnych</code>

        @param w Wektor wyrazow wolnych */
        
      void setWektorWyrazowWolnych(Wektor<T>& w) {
      		wektorWyrazowWolnych = w;
      }
      
      
      /**
        @brief Getter dla macierzy wspolczynnikow

        Pobiera wartosc pola <code>macierzWspolczynnikow</code>

        @return Macierz wspolczynnikow */
        
      Macierz<T> getMacierzWspolczynnikow() const {
      		return macierzWspolczynnikow;
      }
      
      
      /**
        @brief Getter dla wektora wyrazow wolnych

        Pobiera wartosc pola <code>wektorWyrazowWolnych</code>

        @return Wektor wyrazow wolnych */
        
      Wektor<T> getWektorWyrazowWolnych() const{
      		return wektorWyrazowWolnych;
      }
      
      
      /**
        @brief Obliczenie pierwiastkow rownania

        Najwazniejsza metoda programu. Oblicza wyniki ukladu rownan.
        Wykorzystuje do tego metode Crammera - liczy wyznaczniki (metoda Gaussa)
        poszczegolnych zmiennych i dzieli przez wyznacznik glowny.

        @return Wektor wynikow */
        
      Wektor<T> oblicz() {
      		T wyznacznikGlowny = macierzWspolczynnikow.wyznacznik();
			T wyznacznikPomocniczy = 0;
			Macierz<T> kopia(rozmiar);
			unsigned int i;
			for (i = 0; i < rozmiar; i++) {
				kopia = macierzWspolczynnikow.kopia();
				kopia[i] = wektorWyrazowWolnych;
				wyznacznikPomocniczy = kopia.wyznacznik();
				
				//sprawdzenie, co sie dzieje w nietypowych wynikach
				if (wyznacznikGlowny == 0) {
				    if (wyznacznikPomocniczy == 0) {
				        std::cerr << "Kazda liczba spelnia rownanie" << std::endl;
				        T puste = 0;
				        wyniki[i] = puste;
				        continue;
				    }
				    else {
				        std::cerr << "\n####UnhandledException: Brak miejsc zerowych\n";
						Wektor<T> pusty(rozmiar);
				        return pusty;
				    }
				}
				wyniki[i] = wyznacznikPomocniczy/wyznacznikGlowny;
			}

    		return wyniki;
      }
     
     
      /**
        @brief Obliczenie bledu

        Liczenie bledu polegajacego na niedokladnosci obliczen komputerowych.

        @return Wektor bledu */
        
      Wektor<T> policzBlad() {
      		wektorBledu = (macierzWspolczynnikow*wyniki) - wektorWyrazowWolnych;
    		return wektorBledu.kopia();
      }
      
      
      /**
        @brief Obliczanie dlugosc wektora bledu

        Liczone na prawach matematycznych.

        @return Dlugosc wektora bledu */
        
      //TODO NAPRAWIC
      double dlugoscWektoraBledu() {
		  return -1;
      }
      
      
      /**
        @brief Wyswietlanie wyniku

        Metoda typu <code>toString</code>. Ladnie wyswietla wyniki. */
      
      void wyswietlWyniki() {
			unsigned int i;
			for (i = 0; i < rozmiar; i++) {
				std::cout << "x" << i+1 << " = " << wyniki[i] << std::endl;
			}
			std::cout << std::endl;
      }

};


template <typename T>
std::istream& operator >> (std::istream& stream, UkladRownanLiniowych<T>& uklad) {
	Wektor<T> www(uklad.getRozmiar());
	Macierz<T> mw(uklad.getRozmiar());
    stream >> mw;
    stream >> www;
    uklad.setMacierzWspolczynnikow(mw);
    uklad.setWektorWyrazowWolnych(www);
    return stream;
}

template <typename T>
std::ostream& operator << ( std::ostream& stream, const UkladRownanLiniowych<T>& uklad) {
    Macierz<T> transponowana = uklad.getMacierzWspolczynnikow().transponuj();
    unsigned int i;
    for (i = 0; i < uklad.getRozmiar(); i++) {
        stream << transponowana[i];
        stream << " |x" << i+1 << (i == uklad.getRozmiar()/2 ? "| = " : "|   ") << '|' << uklad.getWektorWyrazowWolnych()[i] << '|'<< std::endl;
    }
    return stream;
}


#endif
