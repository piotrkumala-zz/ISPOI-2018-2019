#pragma once

#include"Drawable.h"

//Klasa reprezentujaca tablice punktow ktore da sie narywsowac na ekran
class PointArray:public Drawable{
    int _pkt;
public:
    PointArray(int n):_pkt(n){};
    void draw(){
        cout<<"Rysuje "<<_pkt<<" Punkty"<<endl;
    }
    ~PointArray()=default;
};
