#ifndef SYMENCRYPTWINDOW_H
#define SYMENCRYPTWINDOW_H

#include <QDialog>

namespace Ui {
class SymEncryptWindow;
}

class SymEncryptWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SymEncryptWindow(QWidget *parent = nullptr);
    ~SymEncryptWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SymEncryptWindow *ui;
};

#endif // SYMENCRYPTWINDOW_H
