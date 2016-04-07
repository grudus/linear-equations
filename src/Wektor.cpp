#include "Wektor.hh"

void Wektor::zamienMiejscami(const unsigned int i, const unsigned int j) {
    RODZAJ_DANYCH temp = dane[i];
    dane[i] = dane[j];
    dane[j] = temp;
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


Wektor Wektor::dodaj(const Wektor wektor) {
    Wektor koncowy;
    int i;
    for (i = 0; i < ROZMIAR; i++) koncowy[i] = dane[i] + wektor[i];
    return koncowy;
}

Wektor Wektor::odejmij(const Wektor wektor) {
    Wektor koncowy;
    int i;
    for (i = 0; i < ROZMIAR; i++) koncowy[i] = dane[i] - wektor[i];
    return koncowy;
}

Wektor Wektor::pomnoz(const RODZAJ_DANYCH d) {
    Wektor koncowy;
    int i;
    for (i = 0; i < ROZMIAR; i++) koncowy[i] = dane[i] * d;
    return koncowy;
}

Wektor Wektor::podziel(const RODZAJ_DANYCH d) {
    Wektor koncowy;
    int i;

    if (d == 0) {
        std::cerr << "\n###ArithmeticException\n" << std::endl;
        return koncowy;
    }
    for (i = 0; i < ROZMIAR; i++) koncowy[i] = dane[i] / d;
    return koncowy;
}

RODZAJ_DANYCH Wektor::iloczynSkalarny(const Wektor w) {
    RODZAJ_DANYCH iloczyn = 0;
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        iloczyn += dane[i] * w[i];
    }
    return iloczyn;
}

Wektor Wektor::kopia() {
    Wektor doZwrotu;
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        doZwrotu[i] = dane[i];
    }
    return doZwrotu;
}


std::istream& operator >> (std::istream& stream, Wektor& wek) {
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        stream >> wek[i];
    }
    return stream;
 }

std::ostream& operator << (std::ostream& stream, const Wektor& wek) {
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
