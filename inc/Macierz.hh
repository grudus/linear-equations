#ifndef MACIERZ_HH
#define MACIERZ_HH

/**
    @author Kuba Gruda
    @date 18.04.2016
    @version 1.0

    @file
    @brief Definicja klasy Macierz

    Plik zawiera definicje klasy Macierz. Na jedna macierz
    sklada sie <code>ROZMIAR</code> wektorow. Obiekty tej klasy
    beda wykorzystywane do obliczania rozwiazan ukladow
    rownan liniowych

*/


#include "rozmiar.h"
#include "Wektor.hh"
#include "LZespolone.hh"
#include <iostream>


/**

    @brief Wlasciwa klasa Macierz

    Zawiera ona tylko jedna zmienna - statyczna tablice wektorow o rozmiarze
    <code>ROZMIAR</code> zdefiniowana w pliku <code>rozmiar.h</code>

*/
template <typename T>
class Macierz {
    /**

    @brief Tablica wektorow

    Statyczna tablica przechowywujaca obiekty klasy <code>Wektor</code>
    Jej rozmiar to <code>ROZMIAR</code>
    @see rozmiar.h

    */
  private: Wektor<T> tablica[ROZMIAR];
  unsigned int rozmiar;

  public:
    /**

    @brief Konstruktor domyslny

    W konstruktorze tym wszystkie wektory sa inicjowane domyslnie.

    */
  Macierz() {
    unsigned int i;
    rozmiar = ROZMIAR;
    for (i = 0; i < rozmiar; i++) {
        tablica[i] = Wektor<T>(ROZMIAR);
    }
  }

    Macierz(unsigned int rozm) {
    unsigned int i;
    rozmiar = rozm;
    for (i = 0; i < rozmiar; i++) {
        tablica[i] = Wektor<T>(rozm);
    }
  }

  unsigned int getRozmiar() const {
  	return rozmiar;
  }


  /**
    @brief Liczenie wyznacznika macierzy

    Metoda ta liczy wyznacznik danej macierzy metoda Gaussa.
    Dzieki temu mozliwe jest wyliczenie dla kazdej wielkosci macierzy

    @return Wyznacznik macierzy */
    
    //Bedziemy dazyc do zamiany macierzy w trojkatna - wowczas wyznacznik to iloczyn przekatnych
	T wyznacznik()  {
		unsigned int i, x, j;
		Macierz macierz = kopia();
		T wyznacznik = 0;
		T pierwszaPierwsza = 0, pierwsza = 0;
		bool moznaIscDalej = true;

		// Iterujemy po wszystkich wyrazach z przekatnej macierzy. Nimi bedziemy
		// zerowac wiersze
		for (x = 0; x < rozmiar-1; x++) {
		    pierwszaPierwsza = macierz(x, x);
		    j = x;
		    //Jezeli znaleziona liczba z przekatnej jest rowna 0 - szukamy innej 
		    //dopoki nie znajdziemy
		    while (pierwszaPierwsza == 0) {
		    	std::cerr << "Na przekatnej jest zero\n";
		    	//nie znalezlismy zadnego niezerowego - koniec gry
		  		if (j == rozmiar) {
		            moznaIscDalej = false;
		            break;
		        }
		        macierz.zamienMiejscami(x, ++j);
		        wyznacznik = wyznacznik * -1;
		        pierwszaPierwsza = macierz(x, x);
		    }
		    if (moznaIscDalej) {
		        for (i = x+1; i < rozmiar; i++) {
		            pierwsza = macierz(x, i);
		            //Zerujemy wszystkie wiersza "pod" dzialajacym, zeby uzyskac macierz trojkatna
		            macierz[i] = macierz[i] - (macierz[x]*(pierwsza/pierwszaPierwsza));
		        }
		    }
		    else {
		    	std::cout << "\n###ZerowyArgumentException\n";
		    	T puste = 0;
		    	//cos zwrocic trzeba, hh
		    	return puste;
		    }
		}
		//mnozymy po przekatnej, zatem przez ten krawedziowy argument i tak by trzeba bylo
		wyznacznik = macierz(0, 0);

		for (i = 1; i < rozmiar; i++) {
		        wyznacznik = wyznacznik * macierz(i, i);
		}
		
		return wyznacznik;
  }


  /**
    @brief Getter dla Wektora

    Przeciazenie operatora <code>[]</code>.
    Przyklad uzycia: <p>
    <code> std::cout << macierz[1]; </code> <p>
    W pozyzszym przykladzie zostanie wypisana wartosci wektora znajdujacego
    sie na drugiej pozycji w <code>tablica</code>

    @param i Index. Musi byc nieujemny i mniejszy od rozmiaru tablicy
    @return Wektor o podanym indexie. W przypadku argumentu spoza zakresu
    Wyswietlana jest informacja o bledzie i zwracany Wektor domyslny. */
    
  const Wektor<T> operator[](const unsigned int i) const {
		if (i > rozmiar - 1) {
			std::cerr << "\n###IndexOutOfBoundsException\n";
			return Wektor<T>(rozmiar);
		}
		return tablica[i];
  }
  
  
  /**
    @brief Setter dla Wektora

    Przeciazenie operatora <code>[]</code>. Przyklad uzycia: <p>
    <code> macierz[1] = wektor; </code> <p>
    W powyzszym przykladzie wartosc obiektu wektor zostanie przypisana
    do drugiego elementu tablicy <code>tablica</code> poprzez referencje.

    @param i Index. Musi byc nieujemny i mniejszy od rozmiaru tablicy
    @return Referencja na Wektor o podanym indexie. W przypadku argumentu spoza zakresu
    Wyswietlana jest informacja o bledzie i zwracany Wektor domyslny. */
    
  Wektor<T>& operator[] (const unsigned int i) {
  		if (i > rozmiar - 1) {
			std::cerr << "\n###IndexOutOfBoundsException\n";
			return tablica[0];
		}
		return tablica[i];
  }
  
  
  /**
    @brief Getter dla konkretnej liczby

    Przeciazenie operatora <code>()</code> Metoda zwraca
    <code>RODZAJ_DANYCH</code> - liczbe, ktora jest przechowywana w
    wektorze z tablicy <code>tablica</code> o indexie y na pozycji x.
    Dlatego wyrazenie macierz(x, y) jest logicznie rowne do wyrazenia macierz[y][x].

    @param x Index liczby przechowywanej w tablicy w obiekcie Wektor
    @param y Index wektora przechowywanego w tablicy w obiekcie Macierz
    @return Liczba przechowywana w wektorze */
   
  const T operator() (const unsigned int x, const unsigned int y) const {
  		if (x > rozmiar-1 || y > rozmiar-1) {
  			std::cerr << "\n###IndexOutOfBoundsException\n";
  			T t = 0;
  			return t;
  		}
  		return tablica[y][x];
  }
 

  /**
    @brief Tworzenie kopii konkretnej macierzy

    Metoda pomocnicza. Tworzy i zwraca nowa macierz, ktora wszystkie pola ma takie same
    jak oryginalna macierz.

    @return Nowa Macierz */
   
	Macierz<T> kopia() {
		Macierz<T> doZwrotu(rozmiar);
		unsigned int i;
		for (i = 0; i < rozmiar; i++) {
		    doZwrotu[i] = tablica[i];
		}
		return doZwrotu;
	}
	
	
  /**
    @brief Zamiana miejscami dwoch wektorow w tablicy

    Metoda zamienia dwa wektory z tablicy <code>tablica</code> miejsacmi.
    Wykorzystywane jest w przypadku liczenia wyznacznikow (np. gdy wektor zaczyna sie od 0).
    W przypadku podania jako argument liczby spoza zakresu wyswietlana jest informacja o bledzie
    i zamiana nie ma miejsca.

    @param i Index wektora zamienianego
    @param j Index wektora zamienianego */
    
  void zamienMiejscami(const unsigned int i, const unsigned int j) {
  		if (i > rozmiar-1 || j > rozmiar-1) {
  			std::cerr << "\n###IndexOutOfBoundsException\n";
  			return;
  		}
  		Wektor<T> temp = tablica[i];
  		tablica[i] = tablica[j];
  		tablica[j] = temp;
  }
  

  /**
    @brief Transponowanie macierzy

    Metoda transponuje nowa macierz i zwraca wynik tej operacji

    @return Przetransponowana nowa macierz */

	Macierz<T> transponuj() {
		Macierz<T> transponowana(rozmiar);
		unsigned int i, j;
		for (i = 0; i < rozmiar; i++) {
		    for (j = 0; j < rozmiar; j++) {
		        transponowana[j][i] = tablica[i][j];
		    }
		}
		return transponowana;
	}
};



/**
    @brief Wczytanie macierzy

    Przeciazenie operatora przesuniecia bitowego w prawo.
    Funkcja okresla, w jaki sposob ma zostac wczytany obiekt
    klasy Macierz.

    @param stream Referencja na strumien wejsciowy z ktorego beda czytane dane
    @param macierz Referencja na macierz, do ktorej dane beda zapisywane
    @return Referencja do strumienia podanego jako argument */
    
template <typename T>
std::istream& operator >> (std::istream& stream, Macierz<T>& macierz) {
	unsigned int i;
    for (i = 0; i < macierz.getRozmiar(); i++) {
        stream >> macierz[i];
    }
    return stream;
}


/**
    @brief Wypisywanie macierzy

    Przeciazenie operatora przesuniecia bitowego w lewo.
    Funkcja okresla, w jaki sposob ma zostac wypisany obiekt
    klasy Macierz.

    @param stream Referencja na strumien wyjsciowy do ktorego bedo wypisywane dane
    @param macierz Referencja na macierz, z ktorej beda dane odczytywane
    @return Referencja do strumienia podanego jako argument */
    
template <typename T>
std::ostream& operator << (std::ostream& stream, const Macierz<T>& macierz) {
    unsigned int j;
    Wektor<T> wektor(macierz.getRozmiar());
    for (j = 0; j < macierz.getRozmiar(); j++) {
        wektor = macierz[j];
        stream << wektor <<std::endl;
    }
    return stream;
}


/**
    @brief Mnozenie macierzy przez Wektor

    Przeciazenie operatora *. Funkcja mnozy macierz przez podany
    wektor zgodnie z zasadami matematycznymi. Warunek: Wektor musi miec
    taka sama liczbe kolumn co Macierz wierszy (albo na odwrot)

    @param macierz Macierz do przemnozenia
    @param wektor Wektor, przez ktory bedziemy mnozyc
    @return Wektor - wynik operacji mnozenia */

template <typename T>
Wektor<T> operator* (const Macierz<T> macierz, const Wektor<T> wektor) {
	Wektor<T> pomnozona(macierz.getRozmiar());
    unsigned int i;
    for (i = 0; i < macierz.getRozmiar(); i++) {
        pomnozona[i] = macierz[i] * wektor;
    }
    return pomnozona;
}


#endif
