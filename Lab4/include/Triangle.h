#pragma once
#include"Shape.h"
#include<cmath>

//Klasa reprezentujaca trojkat ktory da sie przesunac i narywowac
class Triangle: public Shape{
    int _a,_b,_c;
public:
    Triangle(int x, int y, int z):_a(x),_b(y),_c(z){};
    void draw(){
        cout<<"Rysuje Trojkat o bokach "<<_a<<", "<<_b<<", "<<_c<<endl;
    };
    float area(){
        float s=(float)(_a+_b+_c)/2;
        return sqrt( s*(s-_a)*(s-_b)*(s-_c) );
    };
    void shift(float a, float b){ cout<<"Przesuwam Trojkat o ("<<a<<", "<<b<<")"<<endl; }
    ~Triangle()=default;
};
