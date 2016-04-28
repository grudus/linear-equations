#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "LZespolone.hh"
#include <unistd.h>


using namespace std;

bool czyZawiera(const char* tab, const int len, char c) {
	for (int i = 0; i < len; i++) if (tab[i] == c) return true;
	return false;
}



template <typename T>
void start (UkladRownanLiniowych<T>& ukladRownanLiniowych, const bool error, const char* rodzaj) {
  cout << "Wprowadz dane " << rodzaj << endl;
  cin >> ukladRownanLiniowych;
  cout << ukladRownanLiniowych << endl;

  ukladRownanLiniowych.oblicz();
  ukladRownanLiniowych.wyswietlWyniki();
  
  Wektor<T> blad = ukladRownanLiniowych.policzBlad();
  if (error) {
	  cout << "Wektor bledu to " << blad << endl;
	  cout << "Jego dlugosc to " << ukladRownanLiniowych.dlugoscWektoraBledu() << endl;
  }
}


int main(int argc, char** argv) {
	//mozliwe typy -> r dla rzeczywistych, z dla zespolonych
  const char typy[] = {'r', 'z'};
  
  bool wyswietlError = false;
  char typ;
  int c;
  
  while ( (c = getopt(argc, argv, "t:e")) != -1) {
    switch (c) {
    case 't':
      if (!optarg) {
      	cerr << "\n###BrakPodanegoTypuException\n";
      	return -1;
      }
      if (optarg[1] != '\0' || !czyZawiera(typy, 2, optarg[0])) {
				cerr << "\n###ZlyTypDanychException\n";
				return -1;
      }
      typ = optarg[0];
      break;
 		case 'e': wyswietlError = true; break;
    default: cerr << "\n###ZlyArgumentException\n"; return -1;
    }
  }     
  
  cout << "Poprawne wywolanie programu: " << endl;
  for (int i = 2; argv[0][i]; i++) cout << argv[0][i];
  cout << "  -t {r|z} [-e]" << endl;

	if (typ == 'r') {
		UkladRownanLiniowych<int> uklad;
		start(uklad, wyswietlError, "rzeczywiste");
	}
	else if (typ == 'z') {
		UkladRownanLiniowych<LZespolona> uklad;
		start(uklad, wyswietlError, "zespolone");
	}
	
	cout << "Koniec\n";
}


