# Uklad rownan liniowych 

##1. Cel cwiczenia:
Wyksztalcenie umiejetnosci modelowania kluczowych dla danego problemu pojecc. Definiowanie własciwego interfejsu klasy.
Zwrocenie uwagi na dobor odpowiednich struktur danych w zaleznosci od metody rozwiazywania problemu. 
Praktyczne zapoznanie sie z problemem skonczonej binarnej reprezentacji liczb oraz wynikajacego 
stad problemu niedokładnosci obliczen.
##2. Program zajec:
  * Demonstracja przykładu problemu skobczonej reprezentacji binarnej liczb
  * Ocena realizacji zadania z poprzedniego laboratorium – ocenie podlega poprawnosc 
realizacji zadania, styl pisania programu oraz opisy.
  * Ocena przygotowania do zajec – ocenie podlega schemat blokowy działania programu
(szczegóły wymagan patrz podrozdział 4) 
  * Modyfikacja programu wg wskazan osoby prowadzacej – ocenie bedzie podlegała poprawnosc
realizacji modyfikacji. Prace nad modyfikacja programu (wszystkie operacje 
nalezy wykonywac na kopii) nalezy rozpoczac juz w trakcie pierwszej fazy laboratorium,
gdyz prowadzacy nie bedzie w stanie ocenic wczeniejszego programu wszystkim jednoczesnie.
  * Realizacja wstepnej fazy prac nad nowym zadaniem – w ramach wstepnej realizacji zadania
nalezy zdefiniowc klase wektor oraz przeciazenia odpowiednich metod. Definicje
nalezy wpisac w odpowiednim module dostarczonego zalacznika.
  * Ocena realizacji wstepnej fazy zadania

##3 Opis zadania programowego:
Nalezy napisacprogram, który umoozliwia rozwiazanie ukladu równan liniowych z trzema niewiadomymi.
Taki uklad rownan wygodnie jest reprezentowac w postaci macierzowej jako
```
|a11 a12 a13|   |x1|   |b1|
|a21 a22 a23| * |x2| = |b2|
|a31 a32 a33|   |x3|   |b3|
```

Tak wie mozna zapisac sformulowany problem w bardziej zwartej i ogólnej postaci:
```
Ax = b
```
gdzie **A** – to macierz współczynników równania, **x** – wektor nieznanych wartosci, ktore 
nalezy wyliczyc, **b** – wektor wyrazow wolnych.
