#include "symdecryptwindow.h"
#include "ui_symdecryptwindow.h"
#include <string>
#include <QMessageBox>
#include "blowfish_encryption.h"
using namespace std;

SymDecryptWindow::SymDecryptWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SymDecryptWindow)
{
    ui->setupUi(this);
}

SymDecryptWindow::~SymDecryptWindow()
{
    delete ui;
}

void SymDecryptWindow::on_pushButton_2_clicked()
{
    // decrypt
    // check key and encrypted text
    QString Qkey = ui->lineEdit->text();
    QString Qtext = ui->lineEdit_2->text();
    string key = Qkey.toStdString();
    string text = Qtext.toStdString();
    if(!blowfishCheckKey(key))
    {
        // show message
        QMessageBox Msgbox;
        Msgbox.setText("Key has to contain only hexadecimal numbers and key length has to be in range of [8, 112] and a multiple of 8");
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
    ui->lineEdit_3->setText(QString::fromStdString(blowfishDecrypt(text, key)));
}

