#include "PArr.h"

Wrapper::Wrapper(char c='a'):type_(c){};

Wrapper* & PArr::operator [](int a)const {
   return *(tab+a);
}

PArr::PArr(int a): size_(a){
    tab= new Wrapper*[size_];
}

PArr::~PArr(){
    for(int i=0;i<size_;++i){
        delete tab[i];
    }
    if(size_==1)
        delete tab;
    else   
        delete[] tab;
}
ostream& operator<<(ostream& out, const PArr&a){
    for(int i=0;i<a.size_;++i){
        a[i]->Wypisz(out);
    }
    return out;
}
 PArr& PArr::operator=( PArr& a){ 
    for(int i=0;i<size_;++i){
        delete (*this)[i];
    }
    if(size_==1)
        delete this->tab;
    else
        delete[] this->tab;
    this->size_=a.size_;
    this->tab=new Wrapper*[a.size_];
    for(int i=0;i<a.size_;++i){
        (*this)[i]=a[i]->Copy();
    }
    return *this;
}