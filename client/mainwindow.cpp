#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inputCount = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->resultList->addItem("Gathering input data");

    ///TODO: collect the data in specific format

    ui->resultList->addItem("Searching started");

    ///TODO: start the search alg.
    ///
    /// Report into ui->resultList

}


void MainWindow::on_firstPersonLatLineEdit_editingFinished()
{
    setReadOnly(ui->firstPersonLatLineEdit,
                ui->firstPersonLongLineEdit,
                ui->secondPersonNameLineEdit,
                ui->secPersonLatLineEdit,
                ui->secPersonLongLineEdit);
    on_secPersonLatLineEdit_editingFinished();
}


void MainWindow::on_firstPersonLongLineEdit_editingFinished()
{
    setReadOnly(ui->firstPersonLatLineEdit,
                ui->firstPersonLongLineEdit,
                ui->secondPersonNameLineEdit,
                ui->secPersonLatLineEdit,
                ui->secPersonLongLineEdit);
    on_secPersonLongLineEdit_editingFinished();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->resultList->clear();
}

void MainWindow::setReadOnly(QLineEdit* latChanged, QLineEdit* longChanged, QLineEdit* nextName, QLineEdit* nextLat, QLineEdit* nextLong)
{

    if(latChanged->isReadOnly() || longChanged->isReadOnly())
    {
        nextLat->setReadOnly(true);
        nextName->setReadOnly(true);
        nextLong->setReadOnly(true);
        return;
    }
    if(!latChanged->text().isEmpty()
            && !longChanged->text().isEmpty() && nextName->isReadOnly())
    {
        ui->resultList->addItem("Edited person registered. Next person enabled.");
        nextLat->setReadOnly(false);
        nextLong->setReadOnly(false);
        nextName->setReadOnly(false);
        return;
    }

    if(!nextName->isReadOnly() && (latChanged->text().isEmpty()
            || longChanged->text().isEmpty()))
    {
        ui->resultList->addItem("Edited person contains invalid data. Next persons disabled.");
        nextLat->setReadOnly(true);
        nextName->setReadOnly(true);
        nextLong->setReadOnly(true);
        return;
    }
}

void MainWindow::on_secPersonLatLineEdit_editingFinished()
{
    setReadOnly(ui->secPersonLatLineEdit,
                ui->secPersonLongLineEdit,
                ui->thirdPersonNameLineEdit,
                ui->thirdPersonLatLineEdit,
                ui->thirdPersonLongLineEdit);
    on_thirdPersonLatLineEdit_editingFinished();
}

void MainWindow::on_secPersonLongLineEdit_editingFinished()
{
    setReadOnly(ui->secPersonLatLineEdit,
                ui->secPersonLongLineEdit,
                ui->thirdPersonNameLineEdit,
                ui->thirdPersonLatLineEdit,
                ui->thirdPersonLongLineEdit);
    on_thirdPersonLongLineEdit_editingFinished();
}

void MainWindow::on_thirdPersonLatLineEdit_editingFinished()
{
    setReadOnly(ui->thirdPersonLatLineEdit,
                ui->thirdPersonLongLineEdit,
                ui->fourthPersonNameLineEdit,
                ui->fourthPersonLatLineEdit,
                ui->fourthPersonLongLineEdit);
    on_fourthPersonLatLineEdit_editingFinished();
}

void MainWindow::on_thirdPersonLongLineEdit_editingFinished()
{
    setReadOnly(ui->thirdPersonLatLineEdit,
                ui->thirdPersonLongLineEdit,
                ui->fourthPersonNameLineEdit,
                ui->fourthPersonLatLineEdit,
                ui->fourthPersonLongLineEdit);
    on_fourthPersonLongLineEdit_editingFinished();
}

void MainWindow::on_fourthPersonLatLineEdit_editingFinished()
{
    setReadOnly(ui->fourthPersonLatLineEdit,
                ui->fourthPersonLongLineEdit,
                ui->fifthPersonNameLineEdit,
                ui->fifthPersonLatLineEdit,
                ui->fifthPersonLongLineEdit);
}

void MainWindow::on_fourthPersonLongLineEdit_editingFinished()
{
    setReadOnly(ui->fourthPersonLatLineEdit,
                ui->fourthPersonLongLineEdit,
                ui->fifthPersonNameLineEdit,
                ui->fifthPersonLatLineEdit,
                ui->fifthPersonLongLineEdit);
}

void MainWindow::on_fifthPersonLatLineEdit_editingFinished()
{

}

void MainWindow::on_fifthPersonLongLineEdit_editingFinished()
{

}
