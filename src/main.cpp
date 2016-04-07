#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;


int main()
{
  UkladRownanLiniowych ukladRownanLiniowych;

  cout << endl << " Start programu " << endl;
  cout << "\n Wczytanie ukladu rownan\n" << endl;

  cin >> ukladRownanLiniowych;
  cout << ukladRownanLiniowych << endl;

  ukladRownanLiniowych.oblicz();
  ukladRownanLiniowych.wyswietlWyniki();

  cout << "Wektor bledu to " << ukladRownanLiniowych.policzBlad() << endl;
  cout << "Jego dlugosc to " << ukladRownanLiniowych.dlugoscWektoraBledu() << endl;

}
