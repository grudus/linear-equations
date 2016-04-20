#include "UkladRownanLiniowych.hh"
#include <cmath>


void UkladRownanLiniowych::setMacierzWspolczynnikow(Macierz m) {macierzWspolczynnikow = m;}
void UkladRownanLiniowych::setWektorWyrazowWolnych(Wektor w) {wektorWyrazowWolnych = w;}

Macierz& UkladRownanLiniowych::getMacierzWspolczynnikow() {return macierzWspolczynnikow;}
Wektor& UkladRownanLiniowych::getWektorWyrazowWolnych() {return wektorWyrazowWolnych;}

Wektor UkladRownanLiniowych::oblicz() {
    RODZAJ_DANYCH wyznacznikGlowny = macierzWspolczynnikow.wyznacznik();
    RODZAJ_DANYCH wyznacznikPomocniczy;
    Macierz kopia(rozmiar);
    unsigned int i;
    for (i = 0; i < rozmiar; i++) {
        kopia = macierzWspolczynnikow.kopia();
        kopia.zamien(i, wektorWyrazowWolnych);
        wyznacznikPomocniczy = kopia.wyznacznik();
        if (wyznacznikGlowny == 0) {
            if (wyznacznikPomocniczy == 0) {
                std::cerr << "Kazda liczba spelnia rownanie" << std::endl;
                wyniki[i] = 666.666;
                continue;
            }
            else {
                std::cerr << "\n####UnhandledException: Brak miejsc zerowych\n";
                return *(new Wektor(rozmiar));
            }
        }
        wyniki[i] = wyznacznikPomocniczy/wyznacznikGlowny;
    }

    return wyniki;
}

Wektor UkladRownanLiniowych::policzBlad() {
    wektorBledu = (macierzWspolczynnikow*wyniki) - wektorWyrazowWolnych;
    return wektorBledu.kopia();
}

RODZAJ_DANYCH UkladRownanLiniowych::dlugoscWektoraBledu() {
    //return sqrt((double) (wektorBledu*wektorBledu));
    return wektorBledu*wektorBledu;
}

void UkladRownanLiniowych::wyswietlWyniki() {
    unsigned int i;
    for (i = 0; i < rozmiar; i++) {
        std::cout << "x" << i+1 << " = " << wyniki[i] << std::endl;
    }
    std::cout << std::endl;
}



std::istream& operator >> (std::istream& stream, UkladRownanLiniowych& uklad) {
    stream >> uklad.getMacierzWspolczynnikow();
    stream >> uklad.getWektorWyrazowWolnych();
    return stream;
}

std::ostream& operator << (std::ostream& stream, UkladRownanLiniowych& uklad) {
    Macierz transponowana = uklad.getMacierzWspolczynnikow().transponuj();
    unsigned int i;
    for (i = 0; i < uklad.getRozmiar(); i++) {
        stream << transponowana[i];
        stream << " |x" << i+1 << (i == uklad.getRozmiar()/2 ? "| = " : "|   ") << '|' << uklad.getWektorWyrazowWolnych()[i] << '|'<< std::endl;
    }
    return stream;
}
