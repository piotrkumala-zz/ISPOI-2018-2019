#pragma once
#include "ColorFilledShape.h"

//Klasa repezentujaca wypeniony ksztalt z kolorowycm brzegiem
class ColorBorderShape: public ColoredShape{
private:
    ColorFilledShape* parent;
    string bordercolor;
public:
    ColorBorderShape(ColoredShape* obj):parent(dynamic_cast<ColorFilledShape*>(obj)), bordercolor("white"){
    };
    void draw() const{ 
        parent->draw();
        cout<<" -- with "<<bordercolor<<" border"<<endl;
    }
    void scale(double s) { parent->scale(s); }
    void setColor(string c){ bordercolor=c;};
    ~ColorBorderShape(){ delete parent;}
};