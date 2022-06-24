#ifndef ASYMENCRYPTWINDOW_H
#define ASYMENCRYPTWINDOW_H

#include <QDialog>

namespace Ui {
class AsymEncryptWindow;
}

class AsymEncryptWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AsymEncryptWindow(QWidget *parent = nullptr);
    ~AsymEncryptWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AsymEncryptWindow *ui;
};

#endif // ASYMENCRYPTWINDOW_H
