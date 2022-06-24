#ifndef SYMDECRYPTWINDOW_H
#define SYMDECRYPTWINDOW_H

#include <QDialog>

namespace Ui {
class SymDecryptWindow;
}

class SymDecryptWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SymDecryptWindow(QWidget *parent = nullptr);
    ~SymDecryptWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::SymDecryptWindow *ui;
};

#endif // SYMDECRYPTWINDOW_H
