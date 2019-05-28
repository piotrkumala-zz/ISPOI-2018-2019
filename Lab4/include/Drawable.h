#pragma once
#include<iostream>
using namespace std;

//Klasa bazowa dla innych klas reprezentujaca obiekt ktory da sie narywsowac
class Drawable{
    public:
        Drawable()=default;
        virtual ~Drawable()=default;
        virtual void draw()=0;      
};