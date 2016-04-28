#ifndef WEKTOR_HH
#define WEKTOR_HH
/**
    @author Kuba Gruda
    @date 18.04.2016
    @version 1.0

    @file
    @brief Definicja klasy Wektor

    Glowna klasa programu. Przechowuje wiadomosci o liczbach uzytych w ukladzie rownan.
*/
#include "rozmiar.h"
#include <iostream>

/**
    @brief Wlasciwa klasa

    Zawiera tylko jedo pole - tablice o rozmiarze <code>ROZMIAR</code> (zdefinowane w pliku rozmiar.h)
    przechowywujaca liczby.
*/
template <typename T>
class Wektor {
    /**
        @brief Tablica danych

        Statyczna tablica przechowywujaca liczby
    */
  private: T dane[ROZMIAR];
  unsigned int rozmiar;
  public:
  /**
    @brief Konstruktor domyslny

    Inicjalizuje wszystkie liczby zerami.
   */

   Wektor() {
        int i;
        rozmiar = ROZMIAR;
        for (i = 0; i < ROZMIAR; i++) {
        	T liczba = 0;
        	dane[i] = liczba;
        }
   }
   Wektor(unsigned int rozm) {
        unsigned int i;
        rozmiar = rozm;
        for (i = 0; i < rozmiar; i++) {
        	T liczba = 0;
        	dane[i] = liczba;
        }
   }

    const unsigned int getRozmiar() const {
    	return rozmiar;
    }
    
    
   /**
    @brief Dodawanie dwoch wektorow

    Metoda dodaje do siebie wszystkie elementy z tablic wektorow
    i zwraca nowy wektor.

    @param wektor Wektor do dodania
    @return Nowy wektor z dodanymi wartosciami */
    
   Wektor<T> operator+(const Wektor<T>& wektor) {
   		Wektor<T> nowy(rozmiar);
   		unsigned int i;
   		for (i = 0; i < rozmiar; i++) nowy[i] = dane[i] + wektor[i];
   		return nowy;
   }
   
   
    /**
    @brief Odejmowanie dwoch wektorow

    Metoda odejmuje od siebie wszystkie liczby z tablic wektorow
    i zwraca nowy wektor.

    @param wektor Wektor do odjecia
    @return Nowy wektor z odjetymi wartosciami */
    
   Wektor<T> operator-(const Wektor<T>& wektor) {
   		Wektor<T> nowy(rozmiar);
   		unsigned int i;
   		for (i = 0; i < rozmiar; i++) nowy[i] = dane[i] - wektor[i];
   		return nowy;
   }
   
  
   /**
    @brief Iloczyn skalarny dwoch wektorow

    Obliczany jest iloczyn wektorowy dwoch wektorow.
    Polega to na pomnozeniu odpowiadajacych sobie (indeksowo) wartosci
    z tablicy danych i dodaniu do siebie.

    @param wektor Wektor do obliczenia iloczynu skalarnego
    @return Iloczyn skalarny */
    
   T operator*(const Wektor<T>& wektor) const {
   		T wynik = 0;
   		unsigned int i;
   		for (i = 0; i < rozmiar; i++) wynik = wynik + dane[i] * wektor[i];
   		return wynik;
   }
   
   
    /**
    @brief Mnozenie wektora przez liczbe

    Metoda mnozy wszystkie wartosci z tablicy danych wektora przez liczbe
    podana w argumencie

    @param d Liczba, przez ktora bedzie pomnozony wektor
    @return Nowy wektor z przemnozonymi wartosciami */
    
   Wektor<T> operator*(const T d) {
   		Wektor<T> nowy = kopia();
   		unsigned int i;
   		for (i = 0; i < rozmiar; i++) nowy[i] = nowy[i] * d;
   		return nowy;
   }
   
   
    /**
    @brief Dzielenie wektora przez liczbe

    Metoda dzieli wszystkie wartosci z tablicy danych wektora przez liczbe
    podana w argumencie. W przypadku podania jako argument 0 wyswietlany jest
    komunikat o bledzie

    @param d Liczba, przez ktora bedzie podzielony wektor
    @return Nowy wektor z przedzielonymi wartosciami */
    
   Wektor<T> operator/(const T d) {
   		Wektor<T> nowy(rozmiar);
   		unsigned int i;
   		if (d == 0) {
   			std::cerr << "\n###DzieleniePrzezZeroException\n";
   			return nowy;
   		}
   		
   		for (i = 0; i < rozmiar; i++) nowy[i] = nowy[i] / d;
   		return nowy;
   }
   
   
   /**
    @brief Zamiana miejscami danych

    Metoda zamienia miejscami liczby w tablicy <code>dane</code>

    @param i Index pierwszej liczby
    @param j Index drugiej liczby */
   
   void zamienMiejscami(const unsigned int i, const unsigned int j) {
	   	T temp = dane[i];
		dane[i] = dane[j];
		dane[j] = temp;	
   }
   
   
   /**
    @brief Getter dla elementow tablicy

    Przeciazenie operatora <code>[]</code> zwracajaca liczbe z tablicy danych.

    @param i Index nalezacy do przedzialu <0, ROZMIAR)
    @return Liczba z tablicy */
    
   const T operator[] (const unsigned int i) const {
	   	if (i > rozmiar-1) {
		    std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
		    T puste = 0;
		    return puste;
		}
		return dane[i];
   }
   
   
    /**
    @brief Setter dla elementow tablicy

    Przeciazenie operatora <code>[]</code> zwracajaca referencje liczby z tablicy danych.

    @param i Index nalezacy do przedzialu <0, ROZMIAR)
    @return Liczba z tablicy */
    
   T& operator[] (const unsigned int i) {
		if (i > rozmiar-1) {
		    std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
		    return dane[0];
		}
		return dane[i];
    }
    
   /**
    @brief Tworzenie kopii wektora

    Wszystkie wartosci z tablicy zostaja przekopiowane do nowego wektora i zwrocone.

    @return Nowy wektor z takimi samymi danymi jak oryginal */
    
   Wektor<T> kopia() {
		Wektor nowy(rozmiar);
		unsigned int i;
		for (i = 0; i < rozmiar; i++) {
		    nowy[i] = dane[i];
		}
		return nowy;
   }
   
  
 	
};


   /**
    @brief Wczytanie wektora

    Przeciazenie operatora przesuniecia bitowego w prawo dla wektora.
    Funkcja wczytuje <code>ROZMIAR</code> danych do tablicy.

    @param stream Referencja do strumienia wejsciowego
    @param wek Referencja na Wektor, do ktorego beda zapisywane dane
    @return Referencja na strumien podany w argumencie */
    
    template <typename T>
	std::istream& operator >> (std::istream& stream, Wektor<T>& wektor) {
		unsigned int i;
		for (i = 0; i < wektor.getRozmiar(); i++) {
		    stream >> wektor[i];
		}
		return stream;
 	}
 	
 	
 	/**
    @brief Wypisywanie wektora

    Przeciazenie operatora przesuniecia bitowego w lewo dla wektora.
    Funkcja wypisuje dane w formacie: <p>
    <code>[a1, a2, a3, ..., an]</code><p>

    @param stream Referencja do strumienia wyjsciowego
    @param wek Stala referencja na Wektor, z ktorego beda odczytywane dane
    @return Referencja na strumien podany w argumencie */
    
    template <typename T>
 	std::ostream& operator << (std::ostream& stream, Wektor<T>& wektor) {
		unsigned int i;
		stream << "[";
		for (i = 0; i < wektor.getRozmiar(); i++) {
		    stream << wektor[i] << (i < wektor.getRozmiar()-1 ? ", " : "]");
		}
		return stream;
	}


#endif

