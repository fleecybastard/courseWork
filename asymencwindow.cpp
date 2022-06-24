#include "asymencwindow.h"
#include "ui_asymencwindow.h"
#include "asymencryptwindow.h"
#include "asymdecryptwindow.h"

AsymEncWindow::AsymEncWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AsymEncWindow)
{
    ui->setupUi(this);
}

AsymEncWindow::~AsymEncWindow()
{
    delete ui;
}

void AsymEncWindow::on_pushButton_clicked()
{
    // encrypt
    AsymEncryptWindow window;
    window.setModal(true);
    window.exec();

}


void AsymEncWindow::on_pushButton_2_clicked()
{
    // decrypt
    AsymDecryptWindow window;
    window.setModal(true);
    window.exec();
}

