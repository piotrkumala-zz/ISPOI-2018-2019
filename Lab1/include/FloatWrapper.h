#pragma once 
#include "PArr.h"
	#include <iomanip> // setprecision
#include <sstream> // stringstream

class FloatWrapper : public Wrapper{
private:
	float _f_;
public:
	FloatWrapper(float f):_f_(f){};
	string Wypisz(){
	stringstream stream;
	stream << fixed << setprecision(1) << _f_;
	return stream.str();
	}
	
};