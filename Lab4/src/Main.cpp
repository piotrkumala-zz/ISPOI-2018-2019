/*
 Celem zadania jest przećwiczenie dziedziczenia wielokrotnego. 
 W tym celu stworzymy hierarchię klas reprezentujących obiekty graficzne: 
 tablica punktow, trójkąt i prostokąt. 

 Dodatkowo, mają one swoje własności (można je rysować, przesuwać i wyliczyć
 powierzchnię), ale tylko jeśli dziedziczą po odpowiednich klasach. Do wyboru 
 mamy klasy: Shape, Drawable, Transformable.

 [Będziemy tu mieć do czynienia z klasami czysto abstrakcyjnymi (w OOP tzw. 
 interfejsami) mającymi tylko funkcje (i destruktory) wirtualne]

 Proszę na podstawie wyniku zgadnąć, jaka jest hierarchia klas oraz napisać 
 niezbędne funkcje.

 Kilka informacji:
 1. Co zwraca dynamic_cast na wskaźnik w razie niepowodzenia?
 2. Powierzchnia trójkąta: sqrt( s(s-a)(s-b)(s-c) ), gdzie s=(a+b+c)/2 oraz 
    a,b,c to długości boków



 Pliku Main.cpp nie modyfikujemy.

 Ostateczny program powinien być przyjazny dla programisty (mieć
 czytelny i dobrze napisany kod).

 Przy wykonaniu zadania nie wolno korzystać z internetu, notatek ani żadnych 
 innych materiałów (w tym własnych wcześniej przygotowanych plików oprocz makefile)

 Program proszę kompilować przynajmniej z flaga -Wall -g oraz -std=c++11 
 Makefile powinien zawierać również cel "clean", który usuwa pliki
 obiektowe i plik wykonywalny.
 */

#include <iostream>
#include "Drawable.h"
#include "Transformable.h"
#include "Shape.h"
#include "PointArray.h"
#include "Triangle.h"
#include "Rectangle.h"

int main() {

	Triangle triangle(2.,3.,4.);
	int num_points = 4;
	PointArray pa( num_points );
	Rectangle rectangle( 2.,3. ); 
	const unsigned num_obj = 3;
	Drawable *obj[num_obj] = { &triangle, &pa, &rectangle };
	for (unsigned i = 0; i < num_obj; ++i)
	{
		obj[i]->draw();
		Shape *shape = dynamic_cast<Shape*>(obj[i]);
		if( shape != nullptr ){
			std::cout << "--- area= " << shape->area() << std::endl;
		}
	}

	std::cout << "====================================" << std::endl;

	for (unsigned i = 0; i < num_obj; ++i)
	{
		Transformable *t = dynamic_cast<Transformable*>(obj[i]);
		if( t != nullptr ){
			t->shift(1.0, 1.0);
		}	
	}
	
	std::cout << "====================================" << std::endl;

	Transformable *t = &triangle;
	t->shift(2.0,2.0);

//	Drawable *dptr = t;		//  ma sie nie kompilowac po odkomentowaniu 
						// (jeśli TYLKO wyrzuca warning: unused variable ‘dptr’, to i tak się kompiluje)

}

/* wynik 

Rysuje Trojkat o bokach 2, 3, 4
--- area= 2.90474
Rysuje 4 Punkty
Rysuje Prostokat o bokach 2, 3
--- area= 6
====================================
Przesuwam Trojkat o (1, 1)
Przesuwam Prostokat o (1, 1)
====================================
Przesuwam Trojkat o (2, 2)

 */