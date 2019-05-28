/*
 Zajęcia nieoceniane.

 Celem zadania jest przećwiczenie specjalizacji częściowych oraz
 klas zagnieżdżonych w szablonach klas. 

 Stworzymy kod do wyliczania w czasie kompilacji zadanego wyrazu 
 ciągu Fibonacciego.

 n-ty wyraz ciągu Fibonacciego dany jest przez:
	F_n = F_{n-1} + F_{n-2} ;  n>1
	F_0 = 0
	F_1 = 1

 rozszerzenie na liczby ujemne:
	F_{n} = F_{n+2} - F_{n+1} ;  n<0

 uwaga:
 - można pisać pomocnicze klasy / struktury, których nie widać w 
   funkcji main.
 - da się to zrobić przy pomocy funkcji zwracającej coś constexpr
   lecz proszę zamiast tego wykorzystać podejście z szablonami
   (w domu można zrobic wersję constexpr).


 Dodatkowo stworzymy stos do przechowywania danych dowolnego typu.
 Proszę napisać szablon klasy Stack w postaci listy połączonej.
 Węzeł (np. klasa Node) listy powinien być klasą zagnieżdżoną w 
 Stack i przechowywać wartość o danym typie i mieć wskażnik na 
 kolejny węzeł. 
 Stack ma wskaźnik na szczyt stosu.
 - po utworzeniu przez konstruktor wskaźnik ten jest nullptr. 
 - funkcja push wkłada obiekt na stos.
 - funkcja pop ściąga obiekt ze szczytu stosu.
   gdy stos jest pusty, pop może rzucać wyjątek (np. std::logic_error)
 - pamiętamy, aby destruktor usuwał dane ze stosu.
 - unikajmy copy-paste

 Proszę nie modyfikować pliku lab12.cpp.

 */

#include <iostream>
#include <string>
#include "Fibonacci.h"
#include "Stack.h"


template<int n>
struct constN{
    constN() { std::cout << n << '\n'; }
};


int main(){
	std::cout << "F_{2}: " << fibonacci<2>::value << std::endl; 
	std::cout << "F_{0}: " << fibonacci<0>::value << std::endl;
	std::cout << "F_{8}: " << fibonacci<8>::value << std::endl;
	std::cout << "F_{-1}: " << fibonacci<-1>::value << std::endl;
	std::cout << "F_{-4}: " << fibonacci<-4>::value << std::endl;
	std::cout << "F_{-5}: " << fibonacci<-5>::value << std::endl;
	std::cout << "F_{-40}: " << fibonacci<-40>::value << std::endl;

	// dla sprawdzenia, czy wyliczane w czasie kompilacji
 	constN<fibonacci<4>::value> out1; 
 	constN<fibonacci<-4>::value> out2; 

 	// stos
 	std::string words[]{"A", "to", "kanapa", "pana", "Kota"};
 	Stack<std::string> wordStack;
 	Stack<std::string> wordStackTest;
 	for (unsigned i = 0; i < sizeof(words)/sizeof(words[0]); ++i){
 		wordStack.push( words[i] );
 		wordStackTest.push( words[i] );
 	}

 	while( !wordStack.isEmpty() )
 		std::cout << wordStack.pop() << " ";
 	std::cout << std::endl;

 	
 	char txt[]{72,71,65,32,107,97,106,32,104,32,97,107,114,101,116,105,108,46,46,46};
 	Stack<char> charStack;
	for (unsigned i = 0; i < sizeof(txt)/sizeof(txt[0]); ++i){
 		charStack.push( txt[i] );
 	}
 	// wynik poniższego kodu pozna Pan/Pani napisaniu szablonu Stack
 	while( !charStack.isEmpty() )
 		std::cout << charStack.pop();
 	std::cout << std::endl;

}

/* wynik

F_{2}: 1
F_{0}: 0
F_{8}: 21
F_{-1}: 1
F_{-4}: -3
F_{-5}: 5
F_{-40}: -102334155
3
-3
Kota pana kanapa to A
[ ta linia pojawi się gdy program zadziała ]

*/

// ściąga jeśli komuś potrzeba:
// N= 	 -8	-7	-6	-5	-4	-3	-2	-1	0	1	2	3	4	5	6	 7	 8
// F_N=	-21	13	-8	 5	-3	 2	-1	 1	0	1	1	2	3	5	8	13	21
