#pragma once
#include<string>
using namespace std;

//klasa pozwalajca na odczyt tekstu:
class ReadAccess{
private:
	string tab_;
public:
	ReadAccess(string);
	ReadAccess()=default;
	~ReadAccess()=default;

	//metoda zwracajaca przesuniecie do nastepnego slowa
	int NextWord(int)const;
	string operator[](int)const ;
	

};

//klasa implementujaca ofSentence, eofWord
class WordAccess{
public:
	static bool eofSentence(string); // statyczna metoda sprawdzajaca czy to juz koniec zdania
	static bool eofWord(char); // statyczna metoda sprawdzajaca czy to juz koniec slowa
};

//klasa pozwalajaca na zapis do tekstu
class ReadWriteAccess{
private:
	string tab_;
public:
	ReadWriteAccess(string s):tab_(s){}
	int NextWord(int);
	string& operator[](int) ;

};