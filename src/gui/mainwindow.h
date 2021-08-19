#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include <qwt_plot_curve.h>
#include <qwt_text.h>
#include "sigestnotfound.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <thread>
#include "pointsbuffer.h"
#include "ipc.h"
#include <tuple>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void run_estimator();


private slots:

    void on_StartButton_released();
    void set_update_plots(bool f){this->update_plots = f;}
    bool get_update_plots(){return this->update_plots;}
    void update_graphs();
    void on_StopButton_clicked();
    void read_graph_data();
    void checkProc();

private:
    Ui::MainWindow *ui;
    bool update_plots = false;

    PointsBuffer out_data;
    PointsBuffer in_data;

    QwtPlotCurve* curve1 = new QwtPlotCurve ("Input Curve");
    QwtPlotCurve* curve2 = new QwtPlotCurve ("Output Curve");
    QTimer* timer;
    QSharedPointer<QProcess> proc;

    QStringList set_up_program();

signals:
    void append_input(QPointF);
    void append_output(QPointF);
};

