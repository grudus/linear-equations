#include "Macierz.hh"


void Macierz::setDane(Wektor* tablicaWektorow) {
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        tablica[i] = tablicaWektorow[i];
    }
}

Wektor Macierz::operator[](unsigned int i) {
    if (i > ROZMIAR-1) {
        std::cerr << "\n###IndexOutOfBoundsException\n" << std::endl;
        return Wektor();
    }
    return tablica[i];
}

std::ostream& operator << (std::ostream& stream, Macierz& macierz) {
    unsigned int j;
    Wektor wektor;
    for (j = 0; j < ROZMIAR; j++) {
        wektor = macierz[j];
        stream << wektor <<std::endl;
    }
    return stream;
}

