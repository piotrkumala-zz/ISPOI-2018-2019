#pragma once
#include <string>
#include<iostream>

//Klasa reprezentujaca wyjatki ktore mozem otrzymac liczac zmienne
class MyTroubles{
private:
    std::string ErrorType; //typ bledu
    int index; // indeks w ktorym wystapil blad
public:
    MyTroubles(std::string s, int i=0):ErrorType(s),index(i){}; //Konstruktor uzywany jezeli blad zalezy od indeksu
    //Wypisanie na ekran typu bledu, obsuguje i te zalezne od miejsca wystepowania i niezalezne od miejsca wystepowania
    void Wypisz()const{
        if(index)
            std::cout<<"zlapalismy: "<<ErrorType<<index<<std::endl;
        else
            std::cout<<"zlapalismy: "<<ErrorType<<std::endl;
    }

    //zwraca typ bledu zaleznego od miejsca wstepowania
    std::string what()const{
        std::string out=ErrorType;
        out+=std::to_string(index);
        return out;
    }
};