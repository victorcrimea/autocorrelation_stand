#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_exit_triggered()
{
	close();
}

void MainWindow::on_runButton_clicked()
{
	QCustomPlot *signalPlot =  ui->signalPlot;

	// generate sine wave:
	QVector<double> x(1001), y(1001); // initialize with entries 0..100
	for (int i=0; i<1001; ++i)
	{
	  x[i] = i; // x goes from 0 to number_of_points
	  y[i] = sind(x[i]); // sine functionb
	}





	// create graph and assign data to it:
	signalPlot->addGraph();
	signalPlot->graph(0)->setData(x, y);
	// give the axes some labels:
	signalPlot->xAxis->setLabel("x");
	signalPlot->yAxis->setLabel("sin(x)");
	// set axes ranges, so we see all data:
	signalPlot->xAxis->setRange(0, 1001);
	signalPlot->yAxis->setRange(-1, 1);
	signalPlot->replot();
}
