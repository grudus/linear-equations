#include "Wektor.hh"
//#include "rozmiar.h"

void Wektor::setDane(RODZAJ_DANYCH d1, RODZAJ_DANYCH d2, RODZAJ_DANYCH d3) {
    dane[0] = d1;
    dane[1] = d2;
    dane[2] = d3;
}

double Wektor::operator[](unsigned int i) {
    if (i > 3) {
        std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
        return 0L;
    }
    else return dane[i];
}


Wektor Wektor::dodaj(Wektor wektor) {
    Wektor koncowy;
    koncowy.setDane(
                    dane[0] + wektor[0],
                    dane[1] + wektor[1],
                    dane[2] + wektor[2]
                    );

    return koncowy;
}

Wektor Wektor::odejmij(Wektor wektor) {
    Wektor koncowy;
    koncowy.setDane(
                    dane[0] - wektor[0],
                    dane[1] - wektor[1],
                    dane[2] - wektor[2]
                    );

    return koncowy;
}

Wektor Wektor::pomnoz(RODZAJ_DANYCH d) {
    Wektor koncowy;
    koncowy.setDane(
                    dane[0] * d,
                    dane[1] * d,
                    dane[2] * d
                    );

    return koncowy;
}

Wektor Wektor::podziel(RODZAJ_DANYCH d) {
    Wektor koncowy;
    if (d == 0) {
        std::cerr << "\n###ArithmeticException\n" << std::endl;
        return koncowy;
    }
    koncowy.setDane(
                    dane[0] / d,
                    dane[1] / d,
                    dane[2] / d
                    );

    return koncowy;
}

RODZAJ_DANYCH Wektor::iloczynSkalarny(Wektor w) {
    return (dane[0] * w[0] + dane[1] * w[1] + dane[2] * w[2]);
}

 std::istream& operator >> (std::istream& stream, /*const*/ Wektor& wek) {
    RODZAJ_DANYCH d1, d2, d3;
    stream >> d1 >> d2 >> d3;
    wek.setDane(d1, d2, d3);
    return stream;
 }

std::ostream& operator << (std::ostream& stream, /*const*/ Wektor& wek) {
    stream << "[" << wek[0] << ", " << wek[1] << ", " << wek[2] << "]";
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
