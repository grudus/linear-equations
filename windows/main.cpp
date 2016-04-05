#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  cout << endl << " Start programu " << endl << endl;
  //UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
  Wektor w1, w2, w3;
  cout << "Podaj dane do 1. wektora: " << endl;
  cin >> w1;
  cout << "Podaj dane do 2. wektora: " << endl;
  cin >> w2;

  cout << w1 << endl;
  cout << w2 << endl;

  w3 = w1 + w2;
  cout << "Dodane: " << w3 << endl;

  w3 = w1 - w2;
  cout << "Odjete: " << w3 << endl;

  w3 = w1 * 4.3;
  cout << "Pomnozone przez 4.3: " << w3 << endl;

  w3 = w1 / 4.3;
  cout << "Podzielone przez 4,3: " << w3 << endl;


  cout << "Iloczyn skalarny: " << (w1 * w2) << endl;




}
