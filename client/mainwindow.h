#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
/*
    void on_lineEdit_textEdited(const QString &arg1);
    void on_lineEdit_2_textEdited(const QString &arg1);
    void on_lineEdit_3_textEdited(const QString &arg1);
    void on_lineEdit_4_textEdited(const QString &arg1);
    void on_lineEdit_5_textEdited(const QString &arg1);
*/

    void on_firstPersonLatLineEdit_editingFinished();
    void on_firstPersonLongLineEdit_editingFinished();

    void on_pushButton_3_clicked();

    void on_secPersonLatLineEdit_editingFinished();

    void on_secPersonLongLineEdit_editingFinished();

    void on_thirdPersonLatLineEdit_editingFinished();

    void on_thirdPersonLongLineEdit_editingFinished();

    void on_fourthPersonLatLineEdit_editingFinished();

    void on_fourthPersonLongLineEdit_editingFinished();

    void on_fifthPersonLatLineEdit_editingFinished();

    void on_fifthPersonLongLineEdit_editingFinished();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    int inputCount;
    Client * c;
    void setReadOnly(QLineEdit * latChanged,
                     QLineEdit * longChanged,
                     QLineEdit * nextName,
                     QLineEdit * nextLat,
                     QLineEdit * nextLong);
};

#endif // MAINWINDOW_H
