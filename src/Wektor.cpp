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

double Wektor::operator[](unsigned int i) {
    if (i > ROZMIAR-1) {
        std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
        return 0L;
    }
    else return dane[i];
}


Wektor Wektor::dodaj(Wektor wektor) {
    Wektor koncowy;
    int i;
    RODZAJ_DANYCH *tablica = new RODZAJ_DANYCH[ROZMIAR];
    for (i = 0; i < ROZMIAR; i++) tablica[i] = dane[i] + wektor[i];
    koncowy.setDane(tablica);
    delete[] tablica;
    return koncowy;
}

Wektor Wektor::odejmij(Wektor wektor) {
    Wektor koncowy;
    int i;
    RODZAJ_DANYCH *tablica = new RODZAJ_DANYCH[ROZMIAR];
    for (i = 0; i < ROZMIAR; i++) tablica[i] = dane[i] - wektor[i];
    koncowy.setDane(tablica);
    delete[] tablica;
    return koncowy;
}

Wektor Wektor::pomnoz(RODZAJ_DANYCH d) {
    Wektor koncowy;
    int i;
    RODZAJ_DANYCH *tablica = new RODZAJ_DANYCH[ROZMIAR];
    for (i = 0; i < ROZMIAR; i++) tablica[i] = dane[i] * d;
    koncowy.setDane(tablica);
    delete[] tablica;
    return koncowy;
}

Wektor Wektor::podziel(RODZAJ_DANYCH d) {
    Wektor koncowy;
    int i;
    RODZAJ_DANYCH *tablica = new RODZAJ_DANYCH[ROZMIAR];

    if (d == 0) {
        std::cerr << "\n###ArithmeticException\n" << std::endl;
        return koncowy;
    }
    for (i = 0; i < ROZMIAR; i++) tablica[i] = dane[i] / d;
    koncowy.setDane(tablica);
    delete[] tablica;
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
    RODZAJ_DANYCH* tablica = new RODZAJ_DANYCH[ROZMIAR];
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        stream >> tablica[i];
    }
    wek.setDane(tablica);
    delete[] tablica;
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
