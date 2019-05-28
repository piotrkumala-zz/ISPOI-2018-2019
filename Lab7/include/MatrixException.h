#pragma once
#include<iostream>

class MatrixException{
public:
    virtual std::string what() const = 0;
    virtual ~MatrixException() = default;
};