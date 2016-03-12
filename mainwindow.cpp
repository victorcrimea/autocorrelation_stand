#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//Signal plot initialization
	signalPlotInit();
	noisePlotInit();
	acfPlotInit();
	ui->statusBar->showMessage("Source code available at https://github.com/victorcrimea/autocorrelation_stand");
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


	// generate sine wave:
	int length = ui->numberOfPoints->value();
	double signalAmplitude = ui->signalAmplitude->value();
	QString signalForm = ui->signalForm->currentText();
	QVector<double> signal;
	if(signalForm == "Sine"){
		signal = Utils::sine(signalAmplitude,length);
	}else if(signalForm == "Cosine"){
		signal = Utils::cosine(signalAmplitude,length);
	}else if(signalForm == "Triangle"){
		signal = Utils::triangle(signalAmplitude,length);
	}else if(signalForm == "Sawtooth"){
		signal = Utils::sawtooth(signalAmplitude,length);
	}
	signalPlotDraw(signal);
	QVector<double> noise = Utils::random(ui->noiseAmplitude->value(), length);
	for(int i=0; i<length; i++){
		signal[i] += noise[i];
	}

	noisePlotDraw(signal);

	Autocorrelation a(signal);

	acfPlotDraw(a.getAutocorrelation());

}

void MainWindow::signalPlotInit()
{
	signalPlot =  ui->signalPlot;
	signalPlot->setBackground(this->palette().background().color());
	signalPlot->addGraph();

	// give the axes some labels:
	signalPlot->xAxis->setLabel("x");
	signalPlot->yAxis->setLabel("signal(x)");
}

void MainWindow::noisePlotInit()
{
	noisePlot =  ui->noisePlot;
	noisePlot->setBackground(this->palette().background().color());
	noisePlot->addGraph();

	// give the axes some labels:
	noisePlot->xAxis->setLabel("x");
	noisePlot->yAxis->setLabel("signal(x)+noise(x)");
}

void MainWindow::acfPlotInit()
{
	acfPlot =  ui->acfPlot;
	acfPlot->setBackground(this->palette().background().color());
	acfPlot->addGraph();

	// give the axes some labels:
	acfPlot->xAxis->setLabel("x");
	acfPlot->yAxis->setLabel("ACF");
}

void MainWindow::signalPlotDraw(QVector<double> data)
{
	double min = DBL_MAX;
	double max = -DBL_MAX;
	for (int i=0; i<data.length(); i++){
		if(data[i] > max) max = data[i];

		if(data[i] < min) min = data[i];
	}

	QVector<double> x(data.length());
	for(int i=0; i<data.length(); i++){
		x[i]=i;
	}

	// create signalPlot and assign data to it:
	signalPlot->graph(0)->setData(x, data);
	// set axes ranges, so we see all data:
	signalPlot->xAxis->setRange(0, data.length());
	signalPlot->yAxis->setRange(min, max);
	signalPlot->replot();
}

void MainWindow::noisePlotDraw(QVector<double> data)
{
	double min = DBL_MAX;
	double max = -DBL_MAX;
	for (int i=0; i<data.length(); i++){
		if(data[i] > max) max = data[i];

		if(data[i] < min) min = data[i];
	}

	QVector<double> x(data.length());
	for(int i=0; i<data.length(); i++){
		x[i]=i;
	}

	// create signalPlot and assign data to it:
	noisePlot->graph(0)->setData(x, data);
	// set axes ranges, so we see all data:
	noisePlot->xAxis->setRange(0, data.length());
	noisePlot->yAxis->setRange(min, max);
	noisePlot->replot();
}

void MainWindow::acfPlotDraw(QVector<double> data)
{
	double min = DBL_MAX;
	double max = -DBL_MAX;
	for (int i=0; i<data.length(); i++){
		if(data[i] > max) max = data[i];

		if(data[i] < min) min = data[i];
	}

	QVector<double> x(data.length());
	for(int i=0; i<data.length(); i++){
		x[i]=i;
	}

	// create signalPlot and assign data to it:
	acfPlot->graph(0)->setData(x, data);
	// set axes ranges, so we see all data:
	acfPlot->xAxis->setRange(0, data.length());
	acfPlot->yAxis->setRange(min, max);
	acfPlot->replot();
}
