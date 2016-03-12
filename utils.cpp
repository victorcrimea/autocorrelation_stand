#include "utils.h"



QVector<double> Utils::sine(double apmlitude, int length)
{
	QVector<double> y(length); // initialize with entries 0..100
	for (int i=0; i<length; ++i)
	{
		y[i] = apmlitude * sind(i); // sine function
	}
	return y;
}

QVector<double> Utils::cosine(double apmlitude, int length)
{
	QVector<double> y(length); // initialize with entries 0..100
	for (int i=0; i<length; ++i)
	{
		y[i] = apmlitude * cosd(i); // cosine function
	}
	return y;
}

QVector<double> Utils::triangle(double apmlitude, int length)
{
	QVector<double> y(length); // initialize with entries 0..100
	for (int i=0; i<length; ++i)
	{
		int xi=i+90;
		double x;
		if(xi%360 < 180){
			x = (double)(xi%360)/180;
		}else {
			x = (180-((double)(xi%360)-180))/180;
		}
		cout << "x=" << x << endl;
		y[i] = apmlitude * (x*2-1); // cosine function
	}
	return y;
}

QVector<double> Utils::sawtooth(double apmlitude, int length)
{
	QVector<double> y(length); // initialize with entries 0..100
	for (int i=0; i<length; ++i)
	{
		double x;
		x = (double)(i%360)/360;
		y[i] = apmlitude * (x*2-1); // cosine function
	}
	return y;
}

QVector<double> Utils::random(double apmlitude, int length)
{
	srand (time(NULL));
	QVector<double> y(length); // initialize with entries 0..100
	for (int i=0; i<length; ++i)
	{
		double r = ((double)rand() / (RAND_MAX))*2 - 1; //random between -1 and 1
		y[i] = apmlitude * r;
		//cout << y[i] << endl;
	}
	return y;
}
