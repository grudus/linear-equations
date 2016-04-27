#ifndef LZESPOLONE_HH
#define LZESPOLONE_HH

/**
    @author Kuba Gruda
    @date 18.04.2016
    @version 1.0

    @file
    @brief Definicja klasy LZespolona

    Objekty klasy LZespolona beda uzywane do przechowywania informacji
    o liczbach nierzeczywistych wprowadzonych przez uzytkownika.

*/

#include "rozmiar.h"
#include <iostream>
#include <string>
#include <stdlib.h>



/**
    @brief Wlasciwa klasa LZespolona

    Zawiera tylko dwie zmienne okreslajace czesc rzeczywista i urojona.
*/
class LZespolona {
    /**
        @brief Pola przechowywujace dane

        W tych prywatnych polach bedzie umieszczona czesc rzeczywista i urojona
        liczby zespolonej. Sa one typu <code>RODZAJ_DANYCH</code>, a jest on okreslony
        w pliku rozmiar.h
    */
    private: double _re, _im;
    unsigned int rozmiar;

    public:
        /**
        @brief Konstrukotr domyslny

        @deprecated
        Inicjalizuje wartosci pol na 0
        */
        LZespolona() {_re = _im = 0;}
        /**
            @brief Konstrukotr wlasciwy

            Tego konstruktora powinno sie uzywac do inicjalizacji obiektow
            LZespolona

            @param re Czesc rzeczywista liczby zespolonej
            @param im Czesc urojona liczby zespolonej

        */
        LZespolona(double re, double im) {
            _re = re;
            _im = im;
        }

        /**
            @brief Setter dla pola _re

            Metoda sluzy do zmiany wartosci pola _re

            @return Referencja do pola _re

        */
        double& Re();
        /**
            @brief Getter dla pola _re

            Metoda sluzyd do pobierania wartosci pola _re.
            Jest oznaczona jako <code>const</code>, zatem nie zmienia ona
            pol klasy.

            @return Wartosc pola _re
        */
        double Re() const;
        /**
            @brief Setter dla pola _im

            Metoda sluzy do zmiany wartosci pola _im

            @return Referencja do pola _im

        */
        double& Im();
            /**
            @brief Getter dla pola _im

            Metoda sluzyd do pobierania wartosci pola _im.
            Jest oznaczona jako <code>const</code>, zatem nie zmienia ona
            pol klasy.

            @return Wartosc pola _im
        */
        double Im() const;

        /**
            @brief Dodawanie liczb zespolonych

            Przeciazenie operatora dodawania dla klas LZespolona. Metoda
            dodaje osobno czesci rzeczywiste i urojone i zwraca nowa instancje
            klasy LZespolona z dodanymi wartosciami

            @param lz Liczba zespolona do dodania
            @return Calkiem nowa liczba zespolona
         */
        LZespolona operator+ (const LZespolona& lz) const;
        /**
            @brief Odejmowanie liczb zespolonych

            Przeciazenie operatora odejmowania dla klas LZespolona. Metoda
            odejmuje osobno czesci rzeczywiste i urojone i zwraca nowa instancje
            klasy LZespolona z odjetymi wartosciami

            @param lz Liczba zespolona do odjecia
            @return Calkiem nowa liczba zespolona
         */
        LZespolona operator- (const LZespolona&) const;
        /**
            @brief Mnozenie liczb zespolonych

            Przeciazenie operatora mnozenia dla klas LZespolona. Metoda
            mnozy osobno czesci rzeczywiste i urojone i zwraca nowa instancje
            klasy LZespolona z pomnozonymi wartosciami

            @param lz Liczba zespolona do pomnozenia
            @return Calkiem nowa liczba zespolona
         */
        LZespolona operator* (const LZespolona&) const;
        LZespolona operator/ (const LZespolona&) const;
        LZespolona operator* (const int) const;
        bool isZero() const {return _im == 0 && _re == 0;}

};

/**
    @brief Wypisanie liczby zespolonej

    Przeciazenie operatora przesuniecia bitowego w lewo dla liczby zespolonej.
    Funkcja opisuje sposob, w jaki powinien byc wypisany obiekt klasy LZespolona.

    @param stream Referencja do strumienia wyjsciowego w ktorym zostana wypisane dane
    @param lz Stala referencja na liczbe zespolona do wypisania
    @return Referencja na strumien przekazany w argumencie
 */
std::ostream& operator<< (std::ostream& stream, const LZespolona& lz);
/**
    @brief Wczytanie liczby zespolonej

    Przeciazenie operatora przesuniecia bitowego w prawo dla liczby zespolonej.
    Wczytywana liczba musi byc formatu <code>{x+-yi}</code>, gdzie x to czesc rzeczywista,
    a y to czesc urojona. Co wiecej, dopuszczalne sa formy:
    <code> {x}, {yi}, {i} </code> oraz analogicznie dla liczb ujemnych.
    Funkcja wczytuje cale wyrazenie jako <code>std::string</code>, a nastepnie
    operuje na podanych wartosciach.

    @param stream Referencja do strumienia wyjsciowego w ktorym zostana wypisane dane
    @param lz Stala referencja na liczbe zespolona do wypisania
    @return Referencja na strumien przekazany w argumencie
 */
std::istream& operator>> (std::istream&, LZespolona&);
/**
    @brief Rozszczepianie stringa

    Pomocnicza funkcja. Rozszczepia podanego w argumencie stringa na tablice
    stringow. Przyklad uzycia: <p>
    <code> splitGdyMinusLubPlus("ga+tta-ba-55+g", &len) => ["ga", "tta", "ba", "55", "g"] </code>

    @param str String do rozszczepienia
    @param len Tutaj zostanie zapisana wielkosc tablicy
    @return Wskaznik na rozszczepiona tablice

 */
std::string* splitGdyMinusLubPlus(std::string str, int* len);


#endif
