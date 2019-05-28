#pragma once

class IntData;
class FloatData;

//Klasa polimorficzna, z ktorej dziedzicza PrintingVisitor i FloatVisitor
class Visitor{
public:
    Visitor()=default;
    virtual ~Visitor()=default;

    //Wirtalne metody odwiedzenia obiektow typu IntData,FloatData
    virtual void visit(IntData*)=0;
    virtual void visit(FloatData*)=0;
};