#pragma once
#include "MatrixException.h"

class IllegalOperation : public MatrixException{
public:
    std::string what()const{
        return "Out of bonds";
    };
    ~IllegalOperation()=default;
};