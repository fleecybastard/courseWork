#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "symencwindow.h"
#include "asymencwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // symmetric encryption
    SymEncWindow window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    // asymmetric encryption
    AsymEncWindow window;
    window.setModal(true);
    window.exec();
}

