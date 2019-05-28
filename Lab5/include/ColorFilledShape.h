#pragma once
#include"Shape.h"
#include"Rectangle.h"
#include"Circle.h"
#include <string>

// Klasa definujaca trzy kolory, red, green, blue
class Colors{
public:
    static string RED;
    static string BLUE;
    static string GREEN;
};

//Klasa reprezentujaca pokolorowany ksztalt
class ColoredShape:public Shape{
public:
    ColoredShape()=default;
    virtual void draw() const=0;
    virtual void scale(double ) =0;
    virtual void setColor(string)=0;
    virtual ~ColoredShape()=default;
};

// Klasa reprezentujaca ksztalt wypelniony kolorem
class ColorFilledShape: public ColoredShape{
private:
    Rectangle* rect_; 
    string color;
public:
    ColorFilledShape(Rectangle* rect): rect_(rect),color("white"){};
    void draw() const{ 
        rect_->draw();
        cout<<" -- with "<<color<<" filling"<<endl;
    }
    void scale(double s) { rect_->scale(s); }
    void setColor(string c){ color=c;};
    ~ColorFilledShape(){ delete rect_; }
};