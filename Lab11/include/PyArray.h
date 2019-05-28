#pragma once
#include<iostream>
#include<cmath>
#include "myerror.h"

// Klasa reprezentujaca talice z ujemnymi indeksami dowolnych typow
template <typename T, const int size>
class PyArray{
    private:
        const int _size_;
        T* tab_;
    public:

    // Operator nawiasu wyrzuca error jezeli index jest poza zakresem, jesli jest w zakresie zwraca referencje
    T& operator [](const int& index){ 
        if(abs(index)>(_size_-1)){
            throw std::out_of_range(std::to_string(index));
        }  
        if(index<0)
            return *(tab_+(size+index)); 
        else
            return *(tab_+index);
    };

    //Wypisuje zawartosc tablicy
    void print(){
        for(int i=0;i<_size_;++i){
            std::cout<<tab_[i]<<" ";
        }
        std::cout<<std::endl;
    }

    PyArray():_size_(size){
        tab_ = new T[_size_];
    }
    ~PyArray(){
        delete[] tab_;
    }
};

template<typename T, typename S>
// Funkcja znajdujaca wieksza z dwoch liczb dowolnego typu
T myMax(T first, S second){
    if(first>second)
        return first;
    else
        return second;
}
// Funkcja sumujaca dwie tablice dowolnych typow i dlugosci
template <typename T, const int size1, typename S, const int size2>
double mySum( PyArray<T, size1> &p1,  PyArray<S, size2> &p2){
    double sum=0.;
    for(int i =0; i < size1; ++i)
        sum+=p1[i];
    for(int i =0; i < size2; ++i)
        sum+=p2[i];
    return sum;
}