#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <cmath>
#include <cstdlib>
#include <cfloat>
#include "qcustomplot.h"

#include "autocorrelation.h"
#include "utils.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_exit_triggered();

	void on_runButton_clicked();

private:
	Ui::MainWindow *ui;
	QCustomPlot *signalPlot;
	QCustomPlot *noisePlot;
	QCustomPlot *acfPlot;

	void signalPlotInit();
	void noisePlotInit();
	void acfPlotInit();

	void signalPlotDraw(QVector<double> data);
	void noisePlotDraw(QVector<double> data);
	void acfPlotDraw(QVector<double> data);
};

#endif // MAINWINDOW_H
