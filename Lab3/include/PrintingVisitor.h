#pragma once
#include"Visitor.h"

//Klasa ktora odwiedza klasy typu IntData, FloatData i wypisuje ich zawartosc na ekran
class PrintingVisitor:public Visitor{
public:
    //Metody odwiedzania IntData,FloatData; wypisuja zawartosci na ekran
    void visit(IntData* I){ std::cout<<" "<<I->get();};
    void visit(FloatData* F){std::cout<<" "<<F->getFloat();};
};