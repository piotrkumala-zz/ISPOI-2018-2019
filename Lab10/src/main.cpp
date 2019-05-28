/*
 Celem zadania jest przećwiczenie szablonów funkcji, 
 w tym ich przeciążania i specjalizacji, a także 
 użycia pozatypowych parametrów szablonu.

 W tym celu napiszemy funkcje służące do sortowania
 różnego rodzaju tablic (i obiektów mających operator[],
 u nas klasy Array przechowującej tablicę int-ów ).

 Dodatkowo proszę napisać szablon struktury/klasy, służący 
 do wyliczenia silni na etapie kompilacji.


 uwagi:
 - sortowanie bąbelkowe np.
	for ( i = 0; i < N; i++ )
		for (j = i+1; j < N; ++j ) 
			if (porownanie(tablica[i], tablica[j]))
				zamiana(tablica[i], tablica[j]) 

 - Można w klasie Array zastosować std::vector. 
   Funkcja reserve(n) klasy vector alokuje jego pojemność na n.

 - tablica std::string jest posortowana po długości wyrazów
   od najkrótszego -- przydatna funkcja length().


 Proszę nie modyfikować pliku lab10.cpp (z wyjątkiem 
 ewentualnego odkomentowania dodatkowego fragmentu).

 Ostateczny program powinien być przyjazny dla programisty (mieć
 czytelny i dobrze napisany kod).

 Przy wykonaniu zadania nie wolno korzystać z internetu, notatek ani żadnych 
 innych materiałów (w tym własnych wcześniej przygotowanych plików oprocz makefile)

 Program proszę kompilować przynajmniej z flaga -Wall -g 
 Makefile powinien zawierać również cel "clean", który usuwa pliki
 obiektowe i plik wykonywalny.
 */

#include <iostream>
#include <string>
#include "Array.h"
#include "Functions.h"

int main(){

	const int tab_size = 5;

	double arrayDouble[tab_size];
	int arrayInt[tab_size];
	Array a(tab_size);

	for (int i = 0; i < tab_size; ++i)
	{
		arrayDouble[i] = 1-0.5*i*i;
		arrayInt[i] = 7-i;
		a[i] = 6-i;
	}

    print( arrayDouble, tab_size );
	print( arrayInt, tab_size );
	print( a, tab_size );

	bubble_sort( arrayDouble, tab_size );
	bubble_sort( arrayInt, tab_size );
	bubble_sort( a, tab_size );

	std::cout << "posortowane: " << std::endl;

	print( arrayDouble, tab_size );
	print( arrayInt, tab_size );
	print( a, tab_size );

	const int tab_str_size=10;
	std::string arrayString[] = {"Lepiej", "kuć", "po", "nocach", "wzorki", "niż", "pakować", "śmieci", "w", "worki"};
	print( arrayString, tab_str_size );
	bubble_sort( arrayString, tab_str_size );
	print( arrayString, tab_str_size );

	// dla dociekliwych: jak napisać funkcję przyjmującą tablicę bez podawania jej rozmiaru?
	 for (int i = 0; i < tab_size; ++i) arrayInt[i] = 7-i;
	 bubble_sort( arrayInt );
	 print( arrayInt );

	// // silnia z wyliczeniem na etapie kompilacji 
	std::cout << "silnia z 6: " << factorial<6>::value << std::endl;
	std::cout << "silnia z 10: " << factorial<10>::value << std::endl;

}

/* wynik

1 0.5 -1 -3.5 -7 
7 6 5 4 3 
6 5 4 3 2 
posortowane: 
-7 -3.5 -1 0.5 1 
3 4 5 6 7 
2 3 4 5 6 
Lepiej kuć po nocach wzorki niż pakować śmieci w worki 
w po niż kuć worki Lepiej nocach wzorki śmieci pakować 
3 4 5 6 7  					// to jest po odkomentowaniu
silnia z 6: 720
silnia z 10: 3628800

*/