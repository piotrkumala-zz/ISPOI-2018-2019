#pragma once

//Klasa bazowa dla innych klas reprezentujaca obiekt ktory da sie przesunac
class Transformable{
public:
    Transformable()=default;
    virtual void shift(float a, float b)=0;
    virtual ~Transformable()=default;
};