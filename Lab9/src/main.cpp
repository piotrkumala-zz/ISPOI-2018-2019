/*
 Celem zadania jest przećwiczenie szablonów funkcji.
 W tym celu napiszemy funkcje:
 - wybierającą minimum (smaller) i maximum (larger) z dwóch wartości,
   zarówno typów wbudowanych, jak i zdefiniowanych przez nas,
 - znajdującą położenie danego elementu w tablicy (find)

 Dodatkowo stowrzymy klasę Rational (reprezentującą ułamek prosty).
 By umożliwić dla tej klasy operacje porównywania i znajdowania, 
 musi ona mieć odpowiednie operatory (jakie?).


 uwagi:
 - funkcja find w przypadku niepowodzenia niech zwraca index za ostatnim 
   elementem (czyli rozmiar tablicy)
 - napisanie funkcji dla każdego typu osobno - zadanie nie na temat


 Proszę nie modyfikować pliku lab09.cpp

 Ostateczny program powinien być przyjazny dla programisty (mieć
 czytelny i dobrze napisany kod).

 Przy wykonaniu zadania nie wolno korzystać z internetu, notatek ani żadnych 
 innych materiałów (w tym własnych wcześniej przygotowanych plików oprocz makefile)

 Program proszę kompilować przynajmniej z flaga -Wall -g oraz -std=c++11 
 Makefile powinien zawierać również cel "clean", który usuwa pliki
 obiektowe i plik wykonywalny.
 */

#include <iostream>
#include <string>
#include "Rational.h"
#include "tools.h"

int main(){
	// porownanie typow wbudowanych
	std::cout << tools::smaller( 2.2, 4.0 ) << std::endl;
	std::cout << tools::smaller( 12, 5 ) << std::endl;
	std::cout << tools::larger( 12, 5 ) << std::endl;
	
    Rational r1(4,-5);
	const Rational r2(1, 2);
	std::cout << "r1 = " << r1 << ",\tr2 = " << r2 << std::endl;
	std::cout << ( r1 < r2 ) << ", " << ( r1 > r2 ) << std::endl;
	std::cout << tools::smaller( r1, r2 ) << std::endl;
	
	const int size=4;
	int intData[size];
	Rational rationalData[size];
	for ( int i = 0; i < size; ++i ) {
		intData[i] = i+1;
		rationalData[i] = Rational(i,i+1);
	}
	int index = tools::find(intData, size, 3);
	std::cout << "Integer found at: " << index << std::endl;

	index = tools::find(rationalData, size, r1);
	std::cout << "1st rational found at: " << index << std::endl;

	index = tools::find(rationalData, size, r2);
	std::cout << "2nd rational found at: " << index << std::endl;
}

/* wynik

2.2
5
12
r1 = -4/5,	r2 = 1/2
1, 0
-4/5
Integer found at: 2
1st rational found at: 4
2nd rational found at: 1

*/