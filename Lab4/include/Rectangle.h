#pragma once
#include"Shape.h"

//Klasa reprezentujaca prostokat ktory da sie przesunac i narysowac
class Rectangle: public Shape{
    int _a,_b;
public:
    Rectangle(int x, int y):_a(x),_b(y){};
    void draw(){ cout<<"Rysuje Prostokat o bokach "<<_a<<", "<<_b<<endl; };
    float area(){ return _a*_b;};
    void shift(float a, float b){ cout<<"Przesuwam Prostokat o ("<<a<<", "<<b<<")"<<endl; }
    ~Rectangle()=default;
};