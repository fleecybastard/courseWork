#ifndef ASYMDECRYPTWINDOW_H
#define ASYMDECRYPTWINDOW_H

#include <QDialog>

namespace Ui {
class AsymDecryptWindow;
}

class AsymDecryptWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AsymDecryptWindow(QWidget *parent = nullptr);
    ~AsymDecryptWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::AsymDecryptWindow *ui;
};

#endif // ASYMDECRYPTWINDOW_H
