#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "LZespolone.hh"



using namespace std;


int main()
{

  UkladRownanLiniowych ukladRownanLiniowych;
  int rozmiar;

  cout << endl << " Start programu " << endl;
  cout << "\n Wczytanie ukladu rownan\n" << endl;

  cout << "Podaj rozmiar\n";
  cin >> rozmiar;
  ukladRownanLiniowych = UkladRownanLiniowych(rozmiar);

  cout << "Podaj uklad, bo rozmiar to " << rozmiar << "\n";

  cin >> ukladRownanLiniowych;
  cout << ukladRownanLiniowych << endl;

  ukladRownanLiniowych.oblicz();
  ukladRownanLiniowych.wyswietlWyniki();

  cout << "Wektor bledu to " << ukladRownanLiniowych.policzBlad() << endl;
  cout << "Jego dlugosc to " << ukladRownanLiniowych.dlugoscWektoraBledu() << endl;

/*
    int i = 0;
    while (i < 8) {
        LZespolona l1;
        cout << "Podaj liczbe " << endl;
        cin >> l1;
        cout << "Podales " << l1 << endl;
        i++;
    }
*/
/*
    LZespolona l1, l2;
    cin >> l1 >> l2;
    cout << l1*l2 << endl; */

    //cout << "Podales " << l3 << endl;

}
