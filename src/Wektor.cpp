#include "Wektor.hh"
 #include <cstdarg>

void Wektor::setDane(const unsigned int rozmiar, ...) {
    va_list ap;
    unsigned int i;
    va_start(ap, rozmiar);
    for (i = 0; i < rozmiar; i++) {
        dane[i] = va_arg(ap,RODZAJ_DANYCH);
    }
    va_end(ap);
}

void Wektor::setDane(RODZAJ_DANYCH* tablica) {
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        dane[i] = tablica[i];
    }
}

const RODZAJ_DANYCH Wektor::operator[](const unsigned int i) const {
    if (i > ROZMIAR-1) {
        std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
        return 0;
    }
    else return dane[i];
}

RODZAJ_DANYCH& Wektor::operator[] (const unsigned int i) {
    if (i > ROZMIAR-1) {
        std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
        return dane[0];
    }
    else return dane[i];
}


Wektor Wektor::dodaj(Wektor wektor) {
    Wektor koncowy;
    int i;
    for (i = 0; i < ROZMIAR; i++) koncowy[i] = dane[i] + wektor[i];
    return koncowy;
}

Wektor Wektor::odejmij(Wektor wektor) {
    Wektor koncowy;
    int i;
    for (i = 0; i < ROZMIAR; i++) koncowy[i] = dane[i] - wektor[i];
    return koncowy;
}

Wektor Wektor::pomnoz(RODZAJ_DANYCH d) {
    Wektor koncowy;
    int i;
    for (i = 0; i < ROZMIAR; i++) koncowy[i] = dane[i] * d;
    return koncowy;
}

Wektor Wektor::podziel(RODZAJ_DANYCH d) {
    Wektor koncowy;
    int i;

    if (d == 0) {
        std::cerr << "\n###ArithmeticException\n" << std::endl;
        return koncowy;
    }
    for (i = 0; i < ROZMIAR; i++) koncowy[i] = dane[i] / d;
    return koncowy;
}

RODZAJ_DANYCH Wektor::iloczynSkalarny(Wektor w) {
    RODZAJ_DANYCH iloczyn = 0;
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        iloczyn += dane[i] * w[i];
    }
    return iloczyn;
}

std::istream& operator >> (std::istream& stream, Wektor& wek) {
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        stream >> wek[i];
    }
    return stream;
 }

std::ostream& operator << (std::ostream& stream, /*const*/ Wektor& wek) {
    int i;
    stream << "[";
    for (i = 0; i < ROZMIAR; i++) {
        stream << wek[i] << (i < ROZMIAR-1 ? ", " : "]");
    }
    if (i != ROZMIAR) {
        std::cerr << "\n###WrongNumberOfArgumentsException\n";
    }
    return stream;
}

Wektor operator+(Wektor w1, Wektor w2) {
    return w1.dodaj(w2);
}
Wektor operator-(Wektor w1, Wektor w2) {
    return w1.odejmij(w2);
}
RODZAJ_DANYCH operator*(Wektor w1, Wektor w2) {
    return w1.iloczynSkalarny(w2);
}
Wektor operator*(Wektor w1, RODZAJ_DANYCH d) {
    return w1.pomnoz(d);
}
Wektor operator/(Wektor w1, RODZAJ_DANYCH d) {
    return w1.podziel(d);
}
