#pragma once
#include<iostream>
#include<string>

// klasa reprezentujaca tablice intow
class Array{
private:
    int size_;
    int* tab_;
public:
    Array(const int& size):size_(size){    tab_ = new int[size_];   }
    int& operator [](const int& index){    return *(tab_+index);    }
    ~Array(){   delete[] tab_;  }
    
    template <typename T>
    friend void print( T& tablica, const int& size);

    template <typename T>
    friend void bubble_sort( T& tablica, const int& size);
};

