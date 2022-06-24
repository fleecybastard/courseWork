#include "symencwindow.h"
#include "ui_symencwindow.h"
#include "symencryptwindow.h"
#include "symdecryptwindow.h"

SymEncWindow::SymEncWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SymEncWindow)
{
    ui->setupUi(this);
}

SymEncWindow::~SymEncWindow()
{
    delete ui;
}

void SymEncWindow::on_pushButton_clicked()
{
    // encrypt
    SymEncryptWindow window;
    window.setModal(true);
    window.exec();
}


void SymEncWindow::on_pushButton_2_clicked()
{
    // decrypt
    SymDecryptWindow window;
    window.setModal(true);
    window.exec();
}

