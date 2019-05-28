#include "CleverMatrix.h"
#include"IllegalOperation.h"
#include<iostream>
// proszę uzupełnić o odpowiednie include'y i metody; można komentować
		


CleverMatrix CleverMatrix::operator*(const CleverMatrix& c)const{
	if( m_size != c.m_size ){
        IllegalOperation wyjatek;
        throw wyjatek;
        return 0;
	}  
	CleverMatrix tmp(m_size);
	for (int i = 0; i < m_size; ++i){
		for (int j = 0; j < m_size; ++j){
			for (int k = 0; k < m_size; ++k){
				tmp(i,j) += m_data[ mapIdx(i,k) ]*c.m_data[ mapIdx(k,j) ];
			}
		}
	}
	return tmp;
}

int CleverMatrix::mapIdx(int row, int col)const{
	return row*m_size+col;
}

void CleverMatrix::print() const{

	for (int i = 0; i < m_size; ++i){
		for (int j = 0; j < m_size; ++j){
			std::cout << m_data[ mapIdx(i,j) ] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}