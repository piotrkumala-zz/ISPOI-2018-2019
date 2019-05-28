#include "mean.h"

double arithmeticMean(const double* values, int size){
	double mean = 0;
	for (int i = 0; i < size; ++i){
		mean += values[i];
	}
	return mean/size;
}

double geometricMean(const double* values, int size){
	double mean = 1;
	for (int i = 0; i < size; ++i){
		if( values[i]<0 ) throw MyTroubles("Error in geometric: negative value with index ", i);
		mean *= values[i];
	}
	return pow(mean,1./size);
}

double harmonicMean(const double* values, int size){
	double mean = 0;
	for (int i = 0; i < size; ++i){
		mean += 1./values[i];
	}
	if( fabs( mean )<1e-10 ) throw MyTroubles("Error in harmonic: denominator is zero ");
	return size/mean;
}