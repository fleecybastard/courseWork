#ifndef ASYMENCWINDOW_H
#define ASYMENCWINDOW_H

#include <QDialog>

namespace Ui {
class AsymEncWindow;
}

class AsymEncWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AsymEncWindow(QWidget *parent = nullptr);
    ~AsymEncWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AsymEncWindow *ui;
};

#endif // ASYMENCWINDOW_H
