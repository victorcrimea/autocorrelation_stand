#ifndef UTILS_H
#define UTILS_H

#include <QVector>
#include <cstdlib>
#include <iostream>

#define PI 3.14159265

#define sind(x) sin(x*PI/180)
#define cosd(x) cos(x*PI/180)

using namespace std;
class Utils
{
public:
	Utils() = delete;

	static QVector<double> sine(double apmlitude, int length);
	static QVector<double> cosine(double apmlitude, int length);
	static QVector<double> triangle(double apmlitude, int length);
	static QVector<double> sawtooth(double apmlitude, int length);
	static QVector<double> random(double apmlitude, int length);
};

#endif // UTILS_H
