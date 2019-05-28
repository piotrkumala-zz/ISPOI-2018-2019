#pragma once 
#include "PArr.h"

class IntWrapper : public Wrapper{
private:
	int _a_;
public:
	IntWrapper(int x):_a_(x){};
	string Wypisz(){
		return to_string(_a_);
	}
};