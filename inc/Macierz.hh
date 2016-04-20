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
#include <iostream>


/**

    @brief Wlasciwa klasa Macierz

    Zawiera ona tylko jedna zmienna - statyczna tablice wektorow o rozmiarze
    <code>ROZMIAR</code> zdefiniowana w pliku <code>rozmiar.h</code>

*/
class Macierz {
    /**

    @brief Tablica wektorow

    Statyczna tablica przechowywujaca obiekty klasy <code>Wektor</code>
    Jej rozmiar to <code>ROZMIAR</code>
    @see rozmiar.h

    */
  private: Wektor tablica[ROZMIAR];
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
        tablica[i] = Wektor(ROZMIAR);
    }
  }

    Macierz(unsigned int rozm) {
    unsigned int i;
    rozmiar = rozm;
    for (i = 0; i < rozmiar; i++) {
        tablica[i] = Wektor(rozm);
    }
  }

  unsigned int getRozmiar() const {return rozmiar;}

  /**

    @brief Liczenie wyznacznika macierzy

    Metoda ta liczy wyznacznik danej macierzy metoda Gaussa.
    Dzieki temu mozliwe jest wyliczenie dla kazdej wielkosci macierzy

    @return Wyznacznik macierzy

  */
  RODZAJ_DANYCH wyznacznik();

  /**

    @brief Getter dla Wektora

    Przeciazenie operatora <code>[]</code>.
    Przyklad uzycia: <p>
    <code> std::cout << macierz[1]; </code> <p>
    W pozyzszym przykladzie zostanie wypisana wartosci wektora znajdujacego
    sie na drugiej pozycji w <code>tablica</code>

    @param i Index. Musi byc nieujemny i mniejszy od rozmiaru tablicy
    @return Wektor o podanym indexie. W przypadku argumentu spoza zakresu
    Wyswietlana jest informacja o bledzie i zwracany Wektor domyslny.

  */
  const Wektor operator[](const unsigned int i) const;
  /**
    @brief Setter dla Wektora

    Przeciazenie operatora <code>[]</code>. Przyklad uzycia: <p>
    <code> macierz[1] = wektor; </code> <p>
    W powyzszym przykladzie wartosc obiektu wektor zostanie przypisana
    do drugiego elementu tablicy <code>tablica</code> poprzez referencje.

    @param i Index. Musi byc nieujemny i mniejszy od rozmiaru tablicy
    @return Referencja na Wektor o podanym indexie. W przypadku argumentu spoza zakresu
    Wyswietlana jest informacja o bledzie i zwracany Wektor domyslny.

  */
  Wektor& operator[] (const unsigned int);
  /**
    @brief Getter dla konkretnej liczby

    Przeciazenie operatora <code>()</code> Metoda zwraca
    <code>RODZAJ_DANYCH</code> - liczbe, ktora jest przechowywana w
    wektorze z tablicy <code>tablica</code> o indexie y na pozycji x.
    Dlatego wyrazenie macierz(x, y) jest logicznie rowne do wyrazenia macierz[y][x].

    @param x Index liczby przechowywanej w tablicy w obiekcie Wektor
    @param y Index wektora przechowywanego w tablicy w obiekcie Macierz
    @return Liczba przechowywana w wektorze

   */
  const RODZAJ_DANYCH operator() (const unsigned int x, const unsigned int y) const;

  /**
    @brief Tworzenie kopii konkretnej macierzy

    Metoda pomocnicza. Tworzy i zwraca nowa macierz, ktora wszystkie pola ma takie same
    jak oryginalna macierz.

    @return Nowa Macierz
   */
  Macierz kopia();
  /**
    @brief Zamiana miejscami dwoch wektorow w tablicy

    Metoda zamienia dwa wektory z tablicy <code>tablica</code> miejsacmi.
    Wykorzystywane jest w przypadku liczenia wyznacznikow (np. gdy wektor zaczyna sie od 0).
    W przypadku podania jako argument liczby spoza zakresu wyswietlana jest informacja o bledzie
    i zamiana nie ma miejsca.

    @param i Index wektora zamienianego
    @param j Index wektora zamienianego
   */
  void zamienMiejscami(const unsigned int i, const unsigned int j);
  /**
    @brief Zamiana miejscem wektora

    Metoda przyporzadkowuje elementowi o indexie i z tablicy
    <code>tablica</code> wartosc w.
    Nie wiem po co w ogole tego uzywam.

    @param i Index wektora
    @param w Nowy wektor

  */
  void zamien(const unsigned int i, const Wektor w);

  /**
    @brief Transponowanie macierzy

    Metoda transponuje nowa macierz i zwraca wynik tej operacji

    @return Przetransponowana nowa macierz
   */

  Macierz transponuj();
};


/**
    @brief Wczytanie macierzy

    Przeciazenie operatora przesuniecia bitowego w prawo.
    Funkcja okresla, w jaki sposob ma zostac wczytany obiekt
    klasy Macierz.

    @param stream Referencja na strumien wejsciowy z ktorego beda czytane dane
    @param macierz Referencja na macierz, do ktorej dane beda zapisywane
    @return Referencja do strumienia podanego jako argument
    */
std::istream& operator >> (std::istream& stream, Macierz& macierz);
/**
    @brief Wypisywanie macierzy

    Przeciazenie operatora przesuniecia bitowego w lewo.
    Funkcja okresla, w jaki sposob ma zostac wypisany obiekt
    klasy Macierz.

    @param stream Referencja na strumien wyjsciowy do ktorego bedo wypisywane dane
    @param macierz Referencja na macierz, z ktorej beda dane odczytywane
    @return Referencja do strumienia podanego jako argument
    */
std::ostream& operator << (std::ostream& stream, const Macierz& macierz);
/**
    @brief Mnozenie macierzy przez Wektor

    Przeciazenie operatora *. Funkcja mnozy macierz przez podany
    wektor zgodnie z zasadami matematycznymi. Warunek: Wektor musi miec
    taka sama liczbe kolumn co Macierz wierszy (albo na odwrot)

    @param macierz Macierz do przemnozenia
    @param wektor Wektor, przez ktory bedziemy mnozyc
    @return Wektor - wynik operacji mnozenia

 */

Wektor operator* (const Macierz macierz, const Wektor wektor);


#endif
