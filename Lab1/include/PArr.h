#pragma once
#include<iostream>
#include<string>
using namespace std;


class Wrapper{
private:
char type_;
public:
    Wrapper(char c);
    Wrapper()=default;
    virtual ~Wrapper()=default;
    virtual void Wypisz(ostream&)=0;
    virtual Wrapper* Copy()=0;
};

class PArr{
private:
    int size_;
    Wrapper **tab;
public:
    PArr(int a);
    ~PArr();
    Wrapper * & operator [](int a)const;
    friend ostream& operator<<(ostream&, const PArr&);
    PArr& operator=( PArr&);
};