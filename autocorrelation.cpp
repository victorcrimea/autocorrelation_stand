#include "autocorrelation.h"

Autocorrelation::Autocorrelation(QVector<double> signal)
{
	this->signal = signal;
}

QVector<double> Autocorrelation::getAutocorrelation()
{
	//Mean value of all entries in signal
	double sum=0;
	for(int i=0; i < signal.length(); i++){
		sum+=signal[i];
	}
	double mean = sum/signal.length();

	//Sum of quadratic diffs calculation
	double sum_diffs=0;
	for(int i=0; i < signal.length(); i++){
		sum_diffs+= (signal[i] -mean ) * (signal[i] -mean );
	}


	QVector<double> out(signal.length());
	for(int k=0; k<signal.length(); k++){

		//Cross Mean-square value
		double cross_sum = 0;
		for(int i=0; i < signal.length()-k; i++){
			cross_sum+= (signal[i] -mean ) * (signal[i+k] -mean );
			//cout << "cross_sum[" << i << "]" << cross_sum << endl;
		}
		//Correlation coeficient calculation
		double corr_coeff = cross_sum/sum_diffs;
		out[k]=corr_coeff;
		cout << "corr_coeff[" << k << "]" << out[k] << endl;
	}
	return out;
}
