#pragma once

#include"PArr.h"


class IntWrapper: public Wrapper{
private:
    int _a_;
public:
    IntWrapper(int x):Wrapper('i'), _a_(x){}
    void Wypisz(ostream& wyjscie){
        wyjscie<<_a_<<" ";
    }
     Wrapper* Copy(){
        Wrapper* tmp= new IntWrapper(_a_);
        return tmp;
    }
};