#include "asymencryptwindow.h"
#include "ui_asymencryptwindow.h"
#include "rsa_encryption.h"
#include <string>
#include <QMessageBox>
using namespace std;

AsymEncryptWindow::AsymEncryptWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AsymEncryptWindow)
{
    ui->setupUi(this);
}

AsymEncryptWindow::~AsymEncryptWindow()
{
    delete ui;
}

void AsymEncryptWindow::on_pushButton_clicked()
{
    // generate e, d, n ( show d in Message Window )
    long long* values = generateValues();
    long long n = values[2];
    long long e = values[0];
    long long d = values[1];
    ui->lineEdit->setText(QString::fromStdString(to_string(e)));
    ui->lineEdit_4->setText(QString::fromStdString(to_string(n)));
    QMessageBox Msgbox;
    string messageText = "Save your secret key!\nd: "+to_string(d);
    Msgbox.setText(QString::fromStdString(messageText));
    Msgbox.exec();
}


void AsymEncryptWindow::on_pushButton_2_clicked()
{
    // encrypt
    // check e, n and text to encrypt
    string strE = ui->lineEdit->text().toStdString();
    string strN = ui->lineEdit_4->text().toStdString();
    string text = ui->lineEdit_2->text().toStdString();
    long long e, N;
    try
    {
        e = stoll(strE);
        N = stoll(strN);
        if(!checkValues(e, N))
        {
            throw invalid_argument("e and N has to be positive numbers!");
        }
    }
    catch(invalid_argument const& ex)
    {
        QMessageBox Msgbox;
        Msgbox.setText("e or N is not valid!");
        Msgbox.exec();
        return;
    }
    if(!checkText(text))
    {
        QMessageBox Msgbox;
        Msgbox.setText("Text to encrypt is not valid!");
        Msgbox.exec();
        return;
    }
    string cipher = encrypt(text, e, N);
    ui->lineEdit_3->setText(QString::fromStdString(cipher));
}

