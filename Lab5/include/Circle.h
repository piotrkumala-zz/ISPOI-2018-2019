#pragma once
#include"Shape.h"

//Klasa reprezentujaca kolo
class Circle: public Shape{
private:
    int r_;
public:
    Circle(int r): r_(r){};
    void draw() const { cout<<"Circle with radius "<<r_<<endl;}
    void scale(double s) {r_*=s;};
    ~Circle()=default;
};