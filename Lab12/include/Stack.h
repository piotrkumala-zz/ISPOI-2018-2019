#pragma once

template <typename T>
class Stack{
private:
    int licznik=0;
    T *tab;
public: 
    void push (T data){
        if(licznik==0){
            licznik++;
            tab = new T[licznik];
            tab [licznik -1] = data;
        }
        else{
            T tmp[licznik];
            for(int i=0; i<licznik;++i){
                tmp[i]=tab[i];
            }
            delete[] tab;
            licznik++;
            tab = new T[licznik];
            for(int i=0; i < licznik -1;++i)
                tab[i] = tmp[i];
            tab[licznik -1] =data;
        }
    }
    bool isEmpty(){
        if (licznik==0)
            return true;
        else 
            return false;
    }
    T pop(){
        T tmp[licznik];            
        for(int i=0; i<licznik;++i){
            tmp[i]=tab[i];
        }
        delete[] tab;
        licznik--;
        if(licznik>0){
            tab=new T[licznik];
            for(int i=0; i<licznik;++i){
                tab[i]=tmp[i];
            }
        }
        return tmp[licznik];
    }
    ~Stack(){
        if(licznik==1)
            delete tab;
        if(licznik>1)
            delete[] tab;
    }
};