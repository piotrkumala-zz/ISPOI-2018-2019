/*
 Celem zadania jest przećwiczenie mechanizmu wyjątków. 

 W tym celu proszę:
 - stworzyć kilka klas wyjątków, które informują o rodzaju problemu.
 - napisać klasę CleverMatrix, która wyrzuca odpowiednie wyjątki przy:
 	- próbie wyjścia poza zakres macierzy 
 	- próbie mnożenia macierzy o różnych rozmiarach 
 	- próbie utworzenia macierzy symetrycznej z nieprawidłowych danych 
 	  macierz jest symetryczna jeśli A(i,j)=A(j,i)

 Macierz proszę przechowywać w tablicy 1d (ewentualnie std::vector).
 Paczka zawiera operator mnożenia dwóch macierzy, funkcję print i 
 funkcję mapIdx mapującą indeksy 2d na indeks 1d.  Pozostałe klasy 
 i funkcje proszę dopisać (można i trzeba uzupełnić operator mnożenia)

 Uwaga:
 - Warto skorzystać z delegacji konstruktorów w klasie CleverMatrix. 
 - W konstruktorze rzucającym wyjątek proszę wykorzystać funkcyjny blok try catch.
 - Proszę zadbać o brak wycieków pamięci
 - Proszę wypisać komunikat wyjątku ogólnie (zależnie od idx i size)
   wypisanie zafiksowanych cyfr
 

 Proszę nie modyfikować pliku lab07.cpp i functions.h.
 Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
 ani zadnych innych materialow (w tym wlasnych wczesniej
 przygotowanych plikow oprocz makefile)
 */

#include <iostream>
#include <string>
#include "AssumptionError.h"
#include "IllegalOperation.h"
#include "MatrixException.h"
#include "CleverMatrix.h"

#include "functions.h"

int main(){

	int matrixData1[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int matrixData2[]{ 1, 2, 3, 2, 1, 4, 3, 4, 1 };
	int matrixData3[]{ 1, 2, 3, 4 };

	using operation = void (*)(int matrixData1[] , int matrixData2[] , int matrixData3[]);

	operation array[] = { printMatrices, createSymmetricMatrices, accessMatrix, multiplyMatrices };
	
	const int num=4;
	for (int i = 0; i < num; ++i){
		std::cout << "\n________________ Operation number " << i+1 << " ________________" << std::endl;

		try{

			array[i]( matrixData1, matrixData2, matrixData3 );

		}
		catch( const IllegalOperation &e ){
			std::cout << "CATCHED Illegal Operation: [" << e.what() << "]" << std::endl;
		}
		catch( const AssumptionError &e ){
			std::cout << "CATCHED Assumption Error: [" << e.what()  << "]" << std::endl;
		}
		catch( const MatrixException &e ){
			std::cout << "CATCHED other error: [" << e.what()  << "]" << std::endl;
		}

	}
}

/* wynik

________________ Operation number 1 ________________
1 2 3 
4 5 6 
7 8 9 

1 2 3 
2 1 4 
3 4 1 

1 2 
3 4 


________________ Operation number 2 ________________
Problem in the constructor! 
CATCHED Assumption Error: [Matrix is not symmetric]

________________ Operation number 3 ________________
CATCHED Illegal Operation: [Indices (1, 2) out of bounds]

________________ Operation number 4 ________________
14 16 14 
32 37 38 
50 58 62 

CATCHED Illegal Operation: [Sizes are different 3, 2]

*/