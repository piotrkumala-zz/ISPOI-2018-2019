#pragma once
#include <iostream>
using namespace std;

class Wrapper{
public: 
	Wrapper()=default;
	virtual string Wypisz()=0;
	virtual ~Wrapper() = default;
};

class PArr{
private:
	int size;
public:
	Wrapper **ptr;
	PArr(int);
	~PArr();
	friend ostream& operator<<(ostream& ,PArr const& );
	void operator = (const PArr& tab){
		if(this->size!=tab.size)
		this->size=tab.size;
		for(int i=0; i <tab.size; ++i ){
			this->ptr[i]= tab.ptr[i];
		}
}	
Wrapper* & operator[](int index){
	return ptr[index];
	};
};