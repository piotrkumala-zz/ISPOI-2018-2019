#pragma once
#include"Visitor.h"

//Klasa ktora odwiedza klasy typu IntData, FloatData i zlicza sume ich elementow
class AccumulatingVisitor:public Visitor{
private:
    float sum=0;
public:
    //Metody odwiedzania IntData,FloatData; sumuja elementy
    void visit(IntData* I) { sum+=I->get();};
    void visit(FloatData* F) {sum+=F->getFloat();};

    //Metoda zwracajaca wczesniej zliczona sume elementow odwiedzonych klas
    float getTotalSum()const{return sum;};
};