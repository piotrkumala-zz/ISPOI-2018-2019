#pragma once

#include"PArr.h"


class StringWrapper: public Wrapper{
private:
    string _s_;
public:
    StringWrapper(string s):Wrapper('s'),_s_(s){}
    void Wypisz(ostream& wyjscie){
        wyjscie<<_s_<<" ";
    }
    Wrapper* Copy(){
        Wrapper* tmp= new StringWrapper(_s_);
        return tmp;
    }
};