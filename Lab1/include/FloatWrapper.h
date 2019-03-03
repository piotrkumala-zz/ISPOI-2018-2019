#pragma once

#include"PArr.h"


class FloatWrapper: public Wrapper{
private:
    float _f_;
public:
    FloatWrapper(float x):Wrapper('f'),_f_(x){};
    void Wypisz(ostream& wyjscie){
        wyjscie<<_f_<<" ";
    }
     Wrapper* Copy(){
        Wrapper* tmp= new FloatWrapper(_f_);
        return tmp;
    }
};

