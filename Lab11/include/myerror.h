#pragma once
#include<iostream>
#include<string>

// klasa obslugujaca wyjatki wyjscia poza zakres
class myerror: public std::exception{
public:

//Metoda obsluguje wyjatek wyjscia poza zakres, wypisuje jaki blad popelniono
    static void handle(){
        try{
        throw;
        }
        catch(std::out_of_range e){
        if(*(e.what())<'0')
            std::cout<<"index "<<e.what()<<" is too small\n";
        else
            std::cout<<"index "<<e.what()<<" is  too large\n"; 
        }
    }
};