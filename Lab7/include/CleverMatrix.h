#pragma once
#include<string>
#include<iostream>
using namespace std;
class CleverMatrix{
private:
    int m_size;
    int *m_data;
    std::string m_type;
public:
    CleverMatrix(int size):m_size(size){
        m_data = new int[m_size*m_size];
        for(int i=0;i<m_size*m_size;++i){
            m_data[i]=0;
        }     
    };
    CleverMatrix(int *tab, int size, std::string s="brak"):m_size(size),m_type(s){
        m_data = new int[m_size*m_size];   
        for(int i=0;i<m_size*m_size;++i){
            m_data[i]=tab[i];
        } 
        int syme=0;
        for(int i=0;i<m_size*m_size;++i){
            if(m_data[i]!=m_data[m_size*m_size-i]){
                syme++;
            }
        } 
        if(m_type=="symmetric" and syme){
            cout<<"Blad w konstruktorze"<<endl;
        }
    };
    
    int& operator()(int a, int b){
       return m_data[ mapIdx(a,b) ];
    }
    CleverMatrix operator*(const CleverMatrix& c)const;
    int mapIdx(int row, int col)const;
    void print() const;
    
    ~CleverMatrix(){
            delete[] m_data;
    }
};