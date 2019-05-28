#pragma once
#include "MatrixException.h"
class AssumptionError : public MatrixException{
public:
    std::string what()const{
        return "Nie wiem";
    };
    ~AssumptionError()=default;
};