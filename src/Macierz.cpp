#include "Macierz.hh"


RODZAJ_DANYCH Macierz::wyznacznik()  {
    unsigned int i, x, j;
    Macierz macierz = kopia();
    RODZAJ_DANYCH wyznacznik;
    RODZAJ_DANYCH pierwszaPierwsza, pierwsza;
    bool moznaIscDalej = true;


    for (x = 0; x < rozmiar-1; x++) {
        pierwszaPierwsza = macierz(x, x);
        j = x;
        while (pierwszaPierwsza.isZero()) {
	  std::cerr << "ZERO ZERO\n";  
	  if (j == rozmiar) {
                moznaIscDalej = false;
                break;
            }
            macierz.zamienMiejscami(x, ++j);
            wyznacznik = wyznacznik * -1;
            pierwszaPierwsza = macierz(x, x);
        }
        if (moznaIscDalej) {
            for (i = x+1; i < rozmiar; i++) {
                pierwsza = macierz(x, i);
                macierz[i] = macierz[i] - (macierz[x]*(pierwsza/pierwszaPierwsza));
            }
        }
        else return *(new LZespolona());
    }

    if (moznaIscDalej) if (wyznacznik.isZero()) wyznacznik = macierz(0, 0);

    for (i = 1; i < rozmiar; i++) {
            //std::cout << macierz << "\n";
            wyznacznik = wyznacznik * macierz(i, i);

    }
    return wyznacznik;
  }




Macierz Macierz::kopia() {
    Macierz doZwrotu(rozmiar);
    unsigned int i;
    for (i = 0; i < rozmiar; i++) {
        doZwrotu[i] = tablica[i];
    }
    return doZwrotu;
}

Macierz Macierz::transponuj() {
    Macierz transponowana(rozmiar);
    unsigned int i, j;
    for (i = 0; i < rozmiar; i++) {
        for (j = 0; j < rozmiar; j++) {
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
    if (i > rozmiar-1) {
        std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
        return Wektor(rozmiar);
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
    Wektor pomnozona(macierz.getRozmiar());
    unsigned int i;
    for (i = 0; i < macierz.getRozmiar(); i++) {
        pomnozona[i] = macierz[i] * wektor;
    }
    return pomnozona;
}


std::ostream& operator << (std::ostream& stream, const Macierz& macierz) {
    unsigned int j;
    Wektor wektor(macierz.getRozmiar());
    for (j = 0; j < macierz.getRozmiar(); j++) {
        wektor = macierz[j];
        stream << wektor <<std::endl;
    }
    return stream;
}

std::istream& operator >> (std::istream& stream, Macierz& macierz) {
    unsigned int i;
    for (i = 0; i < macierz.getRozmiar(); i++) {
        stream >> macierz[i];
    }
    return stream;
}

