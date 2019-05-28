#pragma once
#include "Shape.h"

//Klasa reprezentujaca prostokat
class Rectangle: public Shape{
private:
    double a_, b_;
public:
    Rectangle(double a, double b): a_(a), b_(b){};
    Rectangle(double a): a_(a),b_(a){};
    void draw()const {cout<<"Rectangle with sides "<<a_<<", "<<b_<<endl;}
    void scale(double s){a_*=s; b_*=s;};
    void operator *=(double s){ scale(s); };
    double GetA(){ return a_; };
    double GetB(){ return b_; };
    ~Rectangle()=default;
 };