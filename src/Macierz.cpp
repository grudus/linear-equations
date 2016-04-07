#include "Macierz.hh"


RODZAJ_DANYCH Macierz::wyznacznik()  {
    int i, x, j;
    Macierz macierz = kopia();
    RODZAJ_DANYCH wyznacznik = 1;
    RODZAJ_DANYCH pierwszaPierwsza, pierwsza;
    bool moznaIscDalej = true;


    for (x = 0; x < ROZMIAR-1; x++) {
        pierwszaPierwsza = macierz(x, x);
        j = x;
        while (pierwszaPierwsza == 0) {
            if (j == ROZMIAR) {
                moznaIscDalej = false;
                break;
            }
            macierz.zamienMiejscami(x, ++j);
            wyznacznik *= -1;
            pierwszaPierwsza = macierz(x, x);
        }
        if (moznaIscDalej) {
            for (i = x+1; i < ROZMIAR; i++) {
                pierwsza = macierz(x, i);
                macierz[i] = macierz[i] - (macierz[x]*(pierwsza/pierwszaPierwsza));
            }
        }
        else return 0;

    }

    for (i = 0; i < ROZMIAR; i++) wyznacznik *= macierz(i, i);
    return wyznacznik;
  }




Macierz Macierz::kopia() {
    Macierz doZwrotu;
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        doZwrotu[i] = tablica[i];
    }
    return doZwrotu;
}

Macierz Macierz::transponuj() {
    Macierz transponowana;
    int i, j;
    for (i = 0; i < ROZMIAR; i++) {
        for (j = 0; j < ROZMIAR; j++) {
            transponowana[j][i] = tablica[i][j];
        }
    }
    return transponowana;
}

void Macierz::zamienMiejscami(const unsigned int i, const unsigned int j) {
    Wektor temp = tablica[i];
    tablica[i] = tablica[j];
    tablica[j] = temp;
}

void Macierz::zamien(const unsigned int i, const Wektor w) {
    tablica[i] = w;
}


const Wektor Macierz::operator[](const unsigned int i) const {
    if (i > ROZMIAR-1) {
        std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
        return Wektor();
    }
    return tablica[i];
}

const RODZAJ_DANYCH Macierz::operator() (const unsigned int x, const unsigned int y) const {
        return tablica[y][x];
}

Wektor& Macierz::operator[] (const unsigned int i) {
    return tablica[i];
}

Wektor operator*(const Macierz macierz, const Wektor wektor) {
    Wektor pomnozona;
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        pomnozona[i] = macierz[i] * wektor;
    }
    return pomnozona;
}


std::ostream& operator << (std::ostream& stream, const Macierz& macierz) {
    unsigned int j;
    Wektor wektor;
    for (j = 0; j < ROZMIAR; j++) {
        wektor = macierz[j];
        stream << wektor <<std::endl;
    }
    return stream;
}

std::istream& operator >> (std::istream& stream, Macierz& macierz) {
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        stream >> macierz[i];
    }
    return stream;
}

