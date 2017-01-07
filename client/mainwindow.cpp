#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inputCount = 0;
    c = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    ///TODO: collect the data in specific format

    if(c == NULL)
    {
        ui->resultList->addItem("Connect first to the server.");
        return;
    }
    ui->resultList->addItem("Gathering input data");

    // Client * c = new Client("localhost", 2021);
    char buffer[128];
    sprintf(buffer, "Test: %d\n", this->getInputCount());
    c->SendMessageToServer(buffer);
    QString res = c->ReadFromServer().c_str();
    ui->resultList->addItem(res);

    delete c;

    ui->resultList->addItem("Searching started");

    ///TODO: start the search alg.
    ///
    /// Report into ui->resultList

}


int MainWindow::getInputCount()
{
    if(ui->secPersonLongLineEdit->isReadOnly())
    {
        return 0;
    }
    else if(ui->thirdPersonLongLineEdit->isReadOnly())
    {
        return 1;
    }
    else if(ui->fourthPersonLongLineEdit->isReadOnly())
    {
        return 2;
    }
    else if(ui->fifthPersonLongLineEdit->isReadOnly())
    {
        return 3;
    }
    else if(ui->fifthPersonLongLineEdit->text().isEmpty() || ui->fifthPersonLatLineEdit->text().isEmpty() )
    {
        return 4;
    }
    else
    {
        return 5;
    }

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
        ui->resultList->addItem("Edited person contains invalid data. Next persons are disabled.");
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

void MainWindow::on_pushButton_4_clicked()
{
    std::string servername = ui->ServerLineEdit->text().toStdString();
    int port = ui->PortLineEdit->text().toInt(NULL, 10);
    c = new Client(servername, port);
    ui->resultList->addItem("Connected to the server.");
}
