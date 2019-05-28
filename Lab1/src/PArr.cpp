#include "PArr.h"
#include "StringWrapper.h"
PArr::PArr(int x)
:size(x){
ptr = new Wrapper*[size];
}

PArr::~PArr(){
	if(size==1)
		delete ptr;
	else
		delete[] ptr;
}
ostream& operator<<(ostream& wyjscie,PArr const& tab){
	for(int i=0;i <tab.size;++i){
		wyjscie<<tab.ptr[i]->Wypisz();
		wyjscie<<" ";
	}
	return wyjscie;
}
