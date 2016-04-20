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
class Wektor {
    /**
        @brief Tablica danych

        Statyczna tablica przechowywujaca liczby
    */
  private: RODZAJ_DANYCH dane[ROZMIAR];
  unsigned int rozmiar;
  public:
  /**
    @brief Konstruktor domyslny

    Inicjalizuje wszystkie liczby zerami.
   */

   Wektor() {
        int i;
        rozmiar = ROZMIAR;
        for (i = 0; i < ROZMIAR; i++) dane[i] = 0;
   }
   Wektor(unsigned int rozm) {
        unsigned int i;
        rozmiar = rozm;
        for (i = 0; i < rozmiar; i++) dane[i] = 0;
   }

    unsigned int getRozmiar() const {return rozmiar;}
   /**
    @brief Dodawanie dwoch wektorow

    Metoda dodaje do siebie wszystkie liczby z tablic wektorow
    i zwraca nowy wektor.

    @param wektor Wektor do dodania
    @return Nowy wektor z dodanymi wartosciami
   */
   Wektor dodaj(const Wektor wektor);
    /**
    @brief Odejmowanie dwoch wektorow

    Metoda odejmuje od siebie wszystkie liczby z tablic wektorow
    i zwraca nowy wektor.

    @param wektor Wektor do odjecia
    @return Nowy wektor z odjetymi wartosciami
   */
   Wektor odejmij(const Wektor wektor);
   /**
    @brief Iloczyn skalarny dwoch wektorow

    Obliczany jest iloczyn wektorowy dwoch wektorow.
    Polega to na pomnozeniu odpowiadajacych sobie (indeksowo) wartosci
    z tablicy danych i dodaniu do siebie.

    @param w Wektor do obliczenia iloczynu skalarnego
    @return Iloczyn skalarny
    */
   RODZAJ_DANYCH iloczynSkalarny(const Wektor w);
    /**
    @brief Mnozenie wektora przez liczbe

    Metoda mnozy wszystkie wartosci z tablicy danych wektora przez liczbe
    podana w argumencie

    @param d Liczba, przez ktora bedzie pomnozony wektor
    @return Nowy wektor z przemnozonymi wartosciami
   */
   Wektor pomnoz(const RODZAJ_DANYCH d);
    /**
    @brief Dzielenie wektora przez liczbe

    Metoda dzieli wszystkie wartosci z tablicy danych wektora przez liczbe
    podana w argumencie. W przypadku podania jako argument 0 wyswietlany jest
    komunikat o bledzie

    @param d Liczba, przez ktora bedzie podzielony wektor
    @return Nowy wektor z przedzielonymi wartosciami
   */
   Wektor podziel(const RODZAJ_DANYCH d);
   /**
    @brief Zamiana miejscami danych

    Metoda zamienia miejscami liczby w tablicy <code>dane</code>

    @param i Index pierwszej liczby
    @param j Index drugiej liczby
    */
   void zamienMiejscami(const unsigned int i, const unsigned int j);
   /**
    @brief Getter dla elementow tablicy

    Przeciazenie operatora <code>[]</code> zwracajaca liczbe z tablicy danych.

    @param i Index nalezacy do przedzialu <0, ROZMIAR)
    @return Liczba z tablicy
    */
   const RODZAJ_DANYCH operator[] (const unsigned int i) const;
    /**
    @brief Setter dla elementow tablicy

    Przeciazenie operatora <code>[]</code> zwracajaca referencje liczby z tablicy danych.

    @param i Index nalezacy do przedzialu <0, ROZMIAR)
    @return Liczba z tablicy
    */
   RODZAJ_DANYCH& operator[] (const unsigned int);
   /**
    @brief Tworzenie kopii wektora

    Wszystkie wartosci z tablicy zostaja przekopiowane do nowego wektora i zwrocone.

    @return Nowy wektor z takimi samymi danymi jak oryginal
    */
   Wektor kopia();

};


/**
    @brief Wczytanie wektora

    Przeciazenie operatora przesuniecia bitowego w prawo dla wektora.
    Funkcja wczytuje <code>ROZMIAR</code> danych do tablicy.

    @param stream Referencja do strumienia wejsciowego
    @param wek Referencja na Wektor, do ktorego beda zapisywane dane
    @return Referencja na strumien podany w argumencie
 */
std::istream& operator >> (std::istream& stream, Wektor& wek);
/**
    @brief Wypisywanie wektora

    Przeciazenie operatora przesuniecia bitowego w lewo dla wektora.
    Funkcja wypisuje dane w formacie: <p>
    <code>[a1, a2, a3, ..., an]</code><p>

    @param stream Referencja do strumienia wyjsciowego
    @param wek Stala referencja na Wektor, z ktorego beda odczytywane dane
    @return Referencja na strumien podany w argumencie
 */
std::ostream& operator << (std::ostream& stream, const  Wektor& wek);
/**
    @brief Dodawanie wektorow2

    Identycznie jak metoda <code>dodaj</code> z klasy Wektor
 */
Wektor operator+(Wektor, Wektor);
/**
    @brief Odejmowanie wektorow2

    Identycznie jak metoda <code>odejmij</code> z klasy Wektor
 */
Wektor operator-(Wektor, Wektor);
/**
    @brief Iloczyn skalarny wektorow2

    Identycznie jak metoda <code>iloczynSkalarny</code> z klasy Wektor
 */
RODZAJ_DANYCH operator*(Wektor, Wektor);
/**
    @brief Mnozenie przez liczbe

    Identycznie jak metoda <code>pomnoz</code> z klasy Wektor
 */
Wektor operator*(Wektor, RODZAJ_DANYCH);
/**
    @brief Dzielenie przez liczbe

    Identycznie jak metoda <code>podziel</code> z klasy Wektor
 */
Wektor operator/(Wektor, RODZAJ_DANYCH);



#endif
