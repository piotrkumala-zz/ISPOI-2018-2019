/*
 Celem zadania jest przećwiczenie dziedziczenia. 
 Stworzymy hierarchię klas reprezentujących obiekty graficzne.
 Opcjonalnie da się pokolorować ich wnętrze i obwódkę.

 Wymagania:
 -- proszę wykorzystać konstruktor delegujący w klasie Rectangle 
 -- proszę nie powielać tego samego kodu 

 Proszę także używać specyfikatora override

 Zadanie nie jest dokładnym rozszerzeniem programu sprzed tygodnia, ale można 
 wykorzystać część kodu (bez klas Drawable, Transformable i PointsArray).


 Proszę nie modyfikować pliku z funkcją main.

 Ostateczny program powinien być przyjazny dla programisty (mieć
 czytelny i dobrze napisany kod).

 Przy wykonaniu zadania nie wolno korzystać z internetu, notatek ani żadnych 
 innych materiałów (w tym własnych wcześniej przygotowanych plików oprocz makefile)

 Program proszę kompilować przynajmniej z flaga -Wall -g oraz -std=c++11 
 Makefile powinien zawierać również cel "clean", który usuwa pliki
 obiektowe i plik wykonywalny.
 */

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ColorFilledShape.h"
#include "ColorBorderShape.h"

int main() {
	Circle circle(2); // kolo o promieniu 2 
	Rectangle square(5); // prostokat o bokach 5,5
	Rectangle *rect = new Rectangle(2,3);  // prostokat o bokach 2,3

	Shape *obj = &circle;
	obj->draw();

	obj=rect;
	obj->draw();
	obj=&square;
	obj->draw();
	obj->scale(3.0);
	obj->draw();
	
	square*=3.0;
	square.draw();

	std::cout << "====== Colored shapes ======" << std::endl;

	ColoredShape *filledRectangle = new ColorFilledShape(rect);
	filledRectangle->draw();

	filledRectangle->setColor(Colors::RED);
	filledRectangle->draw();
	
	ColoredShape *blueBorderRectangle = new ColorBorderShape(filledRectangle);
	blueBorderRectangle->setColor(Colors::BLUE);
	blueBorderRectangle->draw();

	std::cout << "====== Changed size ======" << std::endl;
	rect->scale(0.5);
	blueBorderRectangle->draw();

	std::cout << "====== Changed colors ======" << std::endl;

	filledRectangle->setColor(Colors::GREEN);
	blueBorderRectangle->draw();
	delete blueBorderRectangle;

}


/* wynik 

Circle with radius 2
Rectangle with sides 2, 3
Rectangle with sides 5, 5
Rectangle with sides 15, 15
Rectangle with sides 45, 45
====== Colored shapes ======
Rectangle with sides 2, 3
 -- with white filling
Rectangle with sides 2, 3
 -- with red filling
Rectangle with sides 2, 3
 -- with red filling
 -- with blue border 
====== Changed size ======
Rectangle with sides 1, 1.5
 -- with red filling
 -- with blue border 
====== Changed colors ======
Rectangle with sides 1, 1.5
 -- with green filling
 -- with blue border 


 */