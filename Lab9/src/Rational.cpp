#include "Rational.h"

std::ostream& operator<<(std::ostream& out,const Rational& ra){
    std::string tmp;
    if(ra.mianownik_< 0){
        tmp="-";
        tmp+=std::to_string(ra.licznik_);
        tmp+="/";
        tmp+=std::to_string(abs(ra.mianownik_));
    }
    else{
        tmp+=std::to_string(ra.licznik_);
        tmp+="/";
        tmp+=std::to_string(ra.mianownik_); 
    }   
    return out<<tmp;
    }