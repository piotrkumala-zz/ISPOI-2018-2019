#pragma once
#include"Drawable.h"
#include"Transformable.h"

//Klasa reprezentujaca baze dla obiektow ktore da sie narysowac i przesunac:
class Shape:public Drawable, public Transformable{
public:
    Shape()=default;
    virtual ~Shape()=default;
    virtual void draw()=0;
    virtual float area()=0;
};