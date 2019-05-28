#pragma once 
#include "PArr.h"
#include<string>

class StringWrapper : public Wrapper{
private:
	string _s_;
public:
	StringWrapper(string x="xd"):_s_(x){};
	string Wypisz(){
		return _s_;
	}
};