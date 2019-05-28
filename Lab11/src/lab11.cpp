/*
 Celem zadania jest przećwiczenie szablonów klas i funkcji z dedukcją 
 typu zwracanego oraz przypomnienie wyjątków.

 Proszę napisać klasę PyArray, która pozwala na dostęp do tablicy w zwykły 
 sposób lub z indeksem od końca tablicy (przy pomocy liczb ujemnych). 
 Długość tablicy jest podawana jako parametr szablonu klasy.

 Jeśli indeks wyjdzie poza dozwolony zakres, czyli [-size, size-1], 
 wyrzucany jest wyjątek (np. std::out_of_range z stdexcept lub napisany
 przez siebie). 

 Dodatkowo proszę napisać funkcje:
 - handle(), która obsługuje wyjątek (wywołując komunikat wyjątku what),
 - myMax wybierającą większą z dwóch wartości dowolnych typów (może być 
   w pliku PyArray.h),
 - mySum sumującą wszystkie elementy dwóch PyArray z dowolnymi typami 
  

 Proszę nie modyfikować pliku lab11.cpp.

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
#include "PyArray.h"
#include "myerror.h"

int main(){
	const int n=7;
	const int m=5;

	PyArray<double, n> arrayDouble;
	PyArray<int, m> arrayInt;

	for (int i = 0; i < m; ++i){
		arrayDouble[i] = 0.45*i*i;
		arrayInt[i] = i+1;
	}
	arrayDouble[-1] = 0.1;
	arrayDouble[-2] = 0.2;

	arrayDouble.print();
	arrayInt.print();

	try{
		arrayInt[-6] = 2; 
	}
	catch(...){
		std::cout << "Handling error..." << std::endl;
		myerror::handle();
	}

	int maxval = myMax( arrayInt[0], arrayInt[1] );
	std::cout << "larger of ints: "<< maxval << std::endl;
	std::cout << "larger of numbers: "<< myMax( arrayInt[0], arrayDouble[0] ) << std::endl;
	

	try{
		for (int i = 0; i < n; ++i){
			std::cout << myMax( arrayDouble[i], arrayInt[i] ) << " ";
		}
		std::cout << std::endl;
	}
	catch(...){
		std::cout << "Handling error..." << std::endl;
		myerror::handle();
	}

	std::cout << "sum of arrays: " << mySum( arrayDouble, arrayInt ) << std::endl;
	
}

/* wynik

0 0.45 1.8 4.05 7.2 0.2 0.1 
1 2 3 4 5 
Handling error...
index -6 is too small
larger of ints: 2
larger of numbers: 1
1 2 3 4.05 7.2 Handling error...
index 5 is too large
sum of arrays: 28.8

*/
