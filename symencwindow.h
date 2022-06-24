#ifndef SYMENCWINDOW_H
#define SYMENCWINDOW_H

#include <QDialog>

namespace Ui {
class SymEncWindow;
}

class SymEncWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SymEncWindow(QWidget *parent = nullptr);
    ~SymEncWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SymEncWindow *ui;
};

#endif // SYMENCWINDOW_H
