#pragma once
#include"mean.h"
#include <iostream>

// klasa reprezentujaca tablice z ktorej bedziemy liczyc srednie
class MeanCalculator{
private:
    double *data_; //tablica ktorej srednie bedziemy liczyc
    int size_; //dlugosc tablicy data_
public:
    //konstruktor tworzacy tablice
    MeanCalculator(double *ptr, int size):size_(size){
        data_=new double[size_];
        for(int i=0; i<size_;++i){
            data_[i]=ptr[i];
        }
    }
    double& operator [](int index){
        if(index>size_ or index<0)
            throw MyTroubles("Array index out of bounds: ", index);
        return data_[index];
    }
    friend std::ostream& operator << (std::ostream& out, MeanCalculator ma);

    //metoda liczaca srednie w zaleznosci jaka stednia kazemy jej policzyc, decyduje o tym x
    void printMean(int x);

    //operator preimkrementacji:
    MeanCalculator operator++(){
        for(int i=0;i<size_;++i){
            this->data_[i]++;
        }
        return *this;
    }
    ~MeanCalculator(){};
};

//klasa przechowujaca statyczne int okreslajace jaka zmienna chcemy liczyc w metodzie printMean
class means{
public:
    static int ARITHMETIC,GEOMETRIC,HARMONIC;
};