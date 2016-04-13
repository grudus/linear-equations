#ifndef LZESPOLONE_HH
#define LZESPOLONE_HH

#include "rozmiar.h"
#include <iostream>
#include <string>
#include <stdlib.h>

class LZespolona {
    private: RODZAJ_DANYCH _re, _im;

    public:
        LZespolona() {_re = _im = 0;}
        LZespolona(RODZAJ_DANYCH re, RODZAJ_DANYCH im) {
            _re = re;
            _im = im;
        }

        //Getters and setters
        RODZAJ_DANYCH& Re();
        RODZAJ_DANYCH Re() const;
        RODZAJ_DANYCH& Im();
        RODZAJ_DANYCH Im() const;


        LZespolona operator+ (const LZespolona&) const;
        LZespolona operator- (const LZespolona&) const;
        LZespolona operator* (const LZespolona&) const;

};

std::ostream& operator<< (std::ostream&, const LZespolona&);
std::istream& operator>> (std::istream&, LZespolona&);
std::string* splitGdyMinusLubPlus(std::string, int*);


#endif
