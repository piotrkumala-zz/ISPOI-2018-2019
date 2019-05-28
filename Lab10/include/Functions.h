#pragma once  
#include"Array.h"
// Fukcja wypisujaca tablice dowolengo typu
template <typename T>
void print( T& tablica, const int& size){
    for(int i=0;i<size;++i){
        std::cout<<tablica[i]<<" ";
    }
    std::cout<<std::endl;
}

// Funkcja sortujaca babelkowo tablice dowolnego typu oprocz string
template <typename T>
void bubble_sort( T& tablica, const int& size){
    int i,j;
    	for (i = 0; i < size; ++i ){
            for (j = i+1; j < size; j++ ){ 
                if (tablica[j] < tablica[i]){
                    double tmp = tablica[j];
                    tablica[j]=tablica[i];
                    tablica[i]= tmp;
                }
            }
        }    
}
// Funkcja sortujaca babelkowo tablice stringow po dlugosci
void bubble_sort( std::string* tablica, const int& size){
    int i,j;
    	for (i = 0; i < size; ++i ){
            for (j = i+1; j < size; j++ ){ 
                if (tablica[j].length() < tablica[i].length()){
                    std::string tmp = tablica[j];
                    tablica[j]=tablica[i];
                    tablica[i]= tmp;
                }
            }
        }    
}

// Funkcja liczaca silnie
int fct(const int& x){
    if(x==0) 
        return 1;
    else
        return x*fct(x-1);
    }

//klasa reprzezntujaca wartosc silni dla podanej liczby
template <int T>
class factorial{
public:
    static int value;
};

template <int T>
int factorial<T>::value=fct(T);

//Funckja wypisujaca tablice dowlonego typu nie znajac jej dlugosci
template <typename T>
void print( T& tablica){
    int k=0,N;

    while(tablica [k]<10){
    N =++k;
    }

    for(int i=0;i<N;++i){
        std::cout<<tablica[i]<<" ";
    }
    std::cout<<std::endl;
}

// Funkcja sortujaca babelkowo tablice dowolnego typu oprocz string nie znajac jej dlugosci
template <typename T>
void bubble_sort( T& tablica){
    int k=0,N;

    while(tablica[k]<10){
    N = ++k;
    }

    int i,j;
    	for (i = 0; i < N; ++i ){
            for (j = i+1; j < N; j++ ){ 
                if (tablica[j] < tablica[i]){
                    int tmp = tablica[j];
                    tablica[j]=tablica[i];
                    tablica[i]= tmp;
                }
            }
        }    
}