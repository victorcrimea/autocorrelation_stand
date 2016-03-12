#include "autocorrelation.h"

Autocorrelation::Autocorrelation(QVector<double> signal)
{
	this->signal = signal;
}

QVector<double> Autocorrelation::getAutocorrelation(int frame)
{
	//Generation of shifted signal
	QVector<double> shifted = signal;

	for(int i=0; i<signal.length()-1; i++){
		if((i+frame) < (signal.length()-1)){
			shifted[i] = signal[i+frame];
		}

		cout << shifted[i] << endl;
	}


	//Convolution of original and shifted signals
	QVector<double> out(1);


	return out;
}
