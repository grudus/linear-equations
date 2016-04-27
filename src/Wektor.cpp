#include "Wektor.hh"
#include "LZespolone.hh"

void Wektor::zamienMiejscami(const unsigned int i, const unsigned int j) {
    RODZAJ_DANYCH temp = dane[i];
    dane[i] = dane[j];
    dane[j] = temp;
}

const RODZAJ_DANYCH Wektor::operator[](const unsigned int i) const {
    if (i > rozmiar-1) {
        std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
        return *(new LZespolona);
    }
    else return dane[i];
}

RODZAJ_DANYCH& Wektor::operator[] (const unsigned int i) {
    if (i > rozmiar-1) {
        std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
        return dane[0];
    }
    else return dane[i];
}


Wektor Wektor::dodaj(const Wektor wektor) {
    Wektor koncowy(rozmiar);
    unsigned int i;
    for (i = 0; i < rozmiar; i++) koncowy[i] = dane[i] + wektor[i];
    return koncowy;
}

Wektor Wektor::odejmij(const Wektor wektor) {
    Wektor koncowy(rozmiar);
    unsigned int i;
    for (i = 0; i < rozmiar; i++) koncowy[i] = dane[i] - wektor[i];
    return koncowy;
}

Wektor Wektor::pomnoz(const RODZAJ_DANYCH d) {
    Wektor koncowy(rozmiar);
    unsigned int i;
    for (i = 0; i < rozmiar; i++) koncowy[i] = dane[i] * d;
    return koncowy;
}

Wektor Wektor::podziel(const RODZAJ_DANYCH d) {
    Wektor koncowy(rozmiar);
    unsigned int i;

    if (d.isZero()) {
        std::cerr << "\n###ArithmeticException\n" << std::endl;
        return koncowy;
    }
    for (i = 0; i < rozmiar; i++) koncowy[i] = dane[i] / d;
    return koncowy;
}

RODZAJ_DANYCH Wektor::iloczynSkalarny(const Wektor w) {
    RODZAJ_DANYCH iloczyn;
    unsigned int i;
    for (i = 0; i < rozmiar; i++) {
        iloczyn = iloczyn + dane[i] * w[i];
    }
    return iloczyn;
}

Wektor Wektor::kopia() {
    Wektor doZwrotu(rozmiar);
    unsigned int i;
    for (i = 0; i < rozmiar; i++) {
        doZwrotu[i] = dane[i];
    }
    return doZwrotu;
}


std::istream& operator >> (std::istream& stream, Wektor& wek) {
    unsigned int i;
    for (i = 0; i < wek.getRozmiar(); i++) {
        stream >> wek[i];
    }
    return stream;
 }

std::ostream& operator << (std::ostream& stream, const Wektor& wek) {
    unsigned int i;
    stream << "[";
    for (i = 0; i < wek.getRozmiar(); i++) {
        stream << wek[i] << (i < wek.getRozmiar()-1 ? ", " : "]");
    }
    if (i != wek.getRozmiar()) {
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
