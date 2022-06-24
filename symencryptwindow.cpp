#include "symencryptwindow.h"
#include "ui_symencryptwindow.h"
#include "blowfish_encryption.h"
#include <QDebug>
#include <string>
#include <QMessageBox>
using namespace std;

SymEncryptWindow::SymEncryptWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SymEncryptWindow)
{
    ui->setupUi(this);
}

SymEncryptWindow::~SymEncryptWindow()
{
    delete ui;
}

void SymEncryptWindow::on_pushButton_clicked()
{
    // generate key
    ui->lineEdit->setText(QString::fromStdString(blowfishGenerateKey()));
}


void SymEncryptWindow::on_pushButton_2_clicked()
{
    // encrypt
    // check key and text to encrypt
    QString Qkey = ui->lineEdit->text();
    QString Qtext = ui->lineEdit_2->text();
    string key = Qkey.toStdString();
    string text = Qtext.toStdString();
    if(!blowfishCheckKey(key))
    {
        // show message
        QMessageBox Msgbox;
        Msgbox.setText("Key has to contain only hexadecimal numbers and key length has to be in range of [8, 112]");
        Msgbox.exec();
        return;
    }
    if(!blowfishCheckText(text))
    {
        // show message
        QMessageBox Msgbox;
        Msgbox.setText("Input has to contain only hexadecimal numbers and input length has to be a multiple of 16");
        Msgbox.exec();
        return;
    }
    ui->lineEdit_3->setText(QString::fromStdString(blowfishEncrypt(text, key)));
}

