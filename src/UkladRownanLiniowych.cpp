#include "UkladRownanLiniowych.hh"
#include <cmath>


void UkladRownanLiniowych::setMacierzWspolczynnikow(Macierz m) {macierzWspolczynnikow = m;}
void UkladRownanLiniowych::setWektorWyrazowWolnych(Wektor w) {wektorWyrazowWolnych = w;}

Macierz& UkladRownanLiniowych::getMacierzWspolczynnikow() {return macierzWspolczynnikow;}
Wektor& UkladRownanLiniowych::getWektorWyrazowWolnych() {return wektorWyrazowWolnych;}

Wektor UkladRownanLiniowych::oblicz() {
    RODZAJ_DANYCH wyznacznikGlowny = macierzWspolczynnikow.wyznacznik();
    RODZAJ_DANYCH wyznacznikPomocniczy;
    Macierz kopia;
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        kopia = macierzWspolczynnikow.kopia();
        kopia.zamien(i, wektorWyrazowWolnych);
        wyznacznikPomocniczy = kopia.wyznacznik();
        if (wyznacznikGlowny == 0) {
            if (wyznacznikPomocniczy == 0) {
                wyniki[i] = 666.666;
                continue;
            }
            else {
                std::cerr << "\n####UnhandledException: Brak miejsc zerowych\n";
                return *(new Wektor());
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
    int i;
    for (i = 0; i < ROZMIAR; i++) {
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
    int i;
    for (i = 0; i < ROZMIAR; i++) {
        stream << transponowana[i];
        stream << " |x" << i+1 << (i == ROZMIAR/2 ? "| = " : "|   ") << '|' << uklad.getWektorWyrazowWolnych()[i] << '|'<< std::endl;
    }
    return stream;
}
