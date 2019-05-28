#pragma once
#include<iostream>
using namespace std;

// Klasa reprezentujaca ksztalt
class Shape{
public:
    Shape()=default;
    virtual ~Shape()=default;
    virtual void draw() const =0;
    virtual void scale(double s) =0;
};