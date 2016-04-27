#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "LZespolone.hh"
#include <unistd.h>


using namespace std;


int main(int argc, char** argv)
{
  
  cout << argv[0] << " nazwa programu" << endl;
  if (argc < 2) {
    cerr << "###NiePodanoEnaException\n";
    return -1;
  }
  int rozm = -1;
  int c;
  while ( (c = getopt(argc, argv, "n:")) != -1) {
    switch (c) {
    case 'n':
      if (optarg) {
	cout << "Podales ladnie " << optarg << "\n";
	rozm = atoi(optarg);
      }
      else {cerr << "Nie podales!" << endl; }
      
      break;
    default: break;
    }


  }     
  if (rozm == -1) {
    cerr << "###NiePodanoPoEnieException\n";
    return -1;
  }

  cout << "Rozmiar to " << rozm << endl;
  

  UkladRownanLiniowych ukladRownanLiniowych(rozm);

  cout << endl << " Start programu " << endl;
  cout << "\n Wczytanie ukladu rownan\n" << endl;

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

    /*LZespolona l1, l2;
    cout << "Podaj liczbe zespolona:\n";
    cin >> l1 >> l2;
    cout << "Podales " << l1 << " i " << l2 << endl;

    cout << "suma to " << l1+l2 << endl;
    cout << "Roznica to " << l1-l2 << endl;
    cout << "Iloczyn to " << l1 * l2 << endl;
    cout << "Iloraz to " << l1/l2 << endl;

    //cout << "Podales " << l3 << endl;
*/
}
