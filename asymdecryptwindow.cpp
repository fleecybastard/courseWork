#include "asymdecryptwindow.h"
#include "ui_asymdecryptwindow.h"
#include "rsa_encryption.h"
#include <string>
#include <QMessageBox>
using namespace std;


AsymDecryptWindow::AsymDecryptWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AsymDecryptWindow)
{
    ui->setupUi(this);
}

AsymDecryptWindow::~AsymDecryptWindow()
{
    delete ui;
}

void AsymDecryptWindow::on_pushButton_2_clicked()
{
    // decrypt
    string strD = ui->lineEdit->text().toStdString();
    string strN = ui->lineEdit_4->text().toStdString();
    string text = ui->lineEdit_2->text().toStdString();
    long long d, N;
    try
    {
        d = stoll(strD);
        N = stoll(strN);
        if(!checkValues(d, N))
        {
            throw invalid_argument("e and N has to be positive numbers!");
        }
    }
    catch(invalid_argument const& ex)
    {
        QMessageBox Msgbox;
        Msgbox.setText("d or N is not valid!");
        Msgbox.exec();
        return;
    }
    if(!checkText(text))
    {
        QMessageBox Msgbox;
        Msgbox.setText("Text to decrypt is not valid!");
        Msgbox.exec();
        return;
    }
    string decryptedText = "";
    try
    {
       decryptedText = decrypt(text, d, N);
    }
    catch(invalid_argument const& ex)
    {
        QMessageBox Msgbox;
        Msgbox.setText("Text to decrypt is not valid!");
        Msgbox.exec();
        return;
    }

    ui->lineEdit_3->setText(QString::fromStdString(decryptedText));
}

