#ifndef AUTOCORRELATION_H
#define AUTOCORRELATION_H

#include <QVector>
#include <QDebug>
#include <iostream>

using namespace std;

class Autocorrelation
{
public:
	Autocorrelation(QVector<double> signal);

	QVector<double> getAutocorrelation();
private:
	QVector<double> signal;
};

#endif // AUTOCORRELATION_H
