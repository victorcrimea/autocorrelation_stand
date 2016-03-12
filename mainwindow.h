#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>

#include "autocorrelation.h"
#define PI 3.14159265

#define sind(x) sin(x*PI/180)

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
};

#endif // MAINWINDOW_H
