/*
 Celem zadania jest przećwiczenie mechanizmu wyjątków. 
 W tym celu stworzymy klasę, która pozwala na wyliczenie
 różnych średnich
 - arytmetyczna <a> = ( Σ a_i )/n
 - geometryczna <a> = ( Π a_i )^(1/n)
 - harmoniczna  <a> = n/( Σ 1/a_i )
 gdzie Σ oznacza sumowanie po indeksie i, a Π oznacza iloczyn. 
 FUNKCJE DO OBLICZEŃ ŚREDNICH SĄ GOTOWE W: means.h, means.cpp

 Funkcje wyrzucają wyjątki -- proszę napisać klasę MeanCalculator,
 która oblicza średnie z wartości podanych w tablicy w bezpieczny 
 sposób oraz posiada kilka dodatkowych operatorów.

 Można użyć vectora!

 ! średnia geometryczna jest okreslona tylko dla liczb a_i>0.
 ! w średniej harmonicznej wyjątek rzucany gdy mianownik jest = 0


 Proszę nie modyfikować pliku z funkcją main, means.h i means.cpp.

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
#include "MeanCalculator.h"
#include "mean.h"

int main(){

	const int size = 4;
	double rawData[size];
	for (int i = 0; i < size; ++i) rawData[i] = (i+1)*(i+1);

	MeanCalculator ma(rawData, size); 
	std::cout << ma << std::endl;

    ma.printMean(means::ARITHMETIC);
	ma.printMean(means::GEOMETRIC);
	ma.printMean(means::HARMONIC);

	std::cout << "=========== Pierwsza podmiana ===========" << std::endl;
	ma[3] = -2;

	ma.printMean(means::ARITHMETIC);
	ma.printMean(means::GEOMETRIC);
	ma.printMean(means::HARMONIC);

	std::cout << "=========== Druga podmiana ===========" << std::endl;
	std::cout << ++ma << std::endl; // zwiekszenie o 1 kazdej wartosci w tablicy
	ma[2] = 10./3.;
	ma.printMean(means::HARMONIC);

	try{
		std::cout << "=========== Trzecia podmiana ===========" << std::endl;
		ma[11] = -4;
		ma[-1] = 444;
		std::cout << "Oops!" << std::endl;
	}
	catch(const MyTroubles &e){
		std::cout << "zlapalismy: " << e.what() << std::endl;
	}
}

/* wynik

1 4 9 16 
Arytmetyczna: 7.5
Arytmetyczna: 4.89898
Harmoniczna: 2.80976
=========== Pierwsza podmiana ===========
Arytmetyczna: 3
zlapalismy: Error in geometric: negative value with index 3
Harmoniczna: 4.64516
=========== Druga podmiana ===========
2 5 10 -1 
zlapalismy: Error in harmonic: denominator is zero 
=========== Trzecia podmiana ===========
zlapalismy: Array index out of bounds: 11


*/