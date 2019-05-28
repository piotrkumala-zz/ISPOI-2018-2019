#pragma once
#include<iostream>
#include<string>
#include<cmath>

// Klasa impementujaca ulamek zwykly:
class Rational{
private:
    int licznik_;
    int mianownik_;
public:
    Rational(int a=0, int b=0):licznik_(a),mianownik_(b){};
    friend std::ostream& operator<<(std::ostream& out,const Rational& ra);

    // Porownanie czy jeden ulamek nie jest mniejszy do drugiego, rzutuje ulamki na double:
    bool operator <(const Rational& ra) const{
        double first, second;
        first = (double)licznik_/(double)mianownik_;
        second = (double)ra.licznik_/(double)ra.mianownik_;
        if(first<second)
            return true;
        else 
            return false;
    }
    // Porownanie czy jeden ulamek nie jest wiekszy do drugiego, rzutuje ulamki na double:
    bool operator >(const Rational& ra) const{
        double first, second;
        first = (double)licznik_/(double)mianownik_;
        second = (double)ra.licznik_/(double)ra.mianownik_;
        if(first>second)
            return true;
        else 
            return false;
    }

    //Operator rownosci dwoch ulamkow, zwraca prawde jezeli liczniki i mianowniki obu ulamkow sa rowne:
    bool operator ==(const Rational& ra) const{
        if(licznik_==ra.licznik_ and mianownik_==ra.mianownik_)
            return true;
        else
            return false;
    }

    ~Rational()=default;
};