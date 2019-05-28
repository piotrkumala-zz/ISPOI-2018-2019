#include"MeanCalculator.h"
#include"MyTroubles.h"
std::ostream& operator << (std::ostream& out, MeanCalculator ma){
    for(int i=0;i<ma.size_;++i){
        out<<ma.data_[i]<<" ";
    }
    return out;
    }

int means::ARITHMETIC = 1;
int means::GEOMETRIC = 2;
int means::HARMONIC = 3;

void MeanCalculator::printMean(int x){
    try{
    switch(x){
        case 1:
        std::cout<<"Arytmetczyna: "<<arithmeticMean(data_, size_)<<std::endl;;
        break;
        case 2:
        std::cout<<"Geometryczna: "<<geometricMean(data_, size_)<<"\n";
        break; 
        case 3:
        std::cout<<"Harmoniczna: "<<harmonicMean(data_, size_)<<"\n";
        break;
    }
    }
    catch(MyTroubles a){
        a.Wypisz();
    }
}
