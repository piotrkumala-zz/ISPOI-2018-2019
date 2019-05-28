#include "WordAccess.h"

#include<iostream>

ReadAccess::ReadAccess(string tekst):tab_(tekst){
}

int ReadAccess::NextWord(int i) const{
	int spacje=0;
	if (i==0)
		return 0;
	else{
		for(unsigned int j=0;j<sizeof(tab_)/sizeof(char);++j){
			if(tab_[j]==' ')
				++spacje;
			if (spacje ==  i)
				return j+1;
		}
	}
	return -1;
}
string ReadAccess::operator[](int a)const{
	int start=this->NextWord(a);
	int end=this->NextWord(a+1);	
	string out;
	for(int i=start;i<end;++i){
		out[i]=tab_[i];
	}
	return out;
}
bool WordAccess::eofSentence(string s){
if(s=="\0")
	return true;
else
	return false;
}
bool WordAccess::eofWord(char s){
if(s=' ')
	return true;
else
	return false;

}
int ReadWriteAccess::NextWord(int i){
	int spacje=0;
	if (i==0)
		return 0;
	else{

		for(unsigned int j=0;j<sizeof(tab_)/sizeof(char);++j){
			if(tab_[j]==' ')
				++spacje;
			if (spacje ==  i)
				return j+1;

		}
	}

}
string& ReadWriteAccess::operator[](int a){
	int start=this->NextWord(a);
	int end=this->NextWord(a+1);	
	string out;
	for(int i=start;i<end;++i){
		out[i]=tab_[i];
	}
	return tab_;
}