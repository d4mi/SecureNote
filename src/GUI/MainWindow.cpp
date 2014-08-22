#include "GUI/MainWindow.h"
#include "ui_MainWindow.h"

#include "QMessageBox"

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leftMenuList->addItem("First");
    ui->leftMenuList->addItem("Second");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_leftMenuList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    //QMessageBox::warning(this, "Hello", "Text " + current->text());
    if( current->text() == "First" )
    {
        ui->mainArea->setCurrentIndex(0);
    }

    if( current->text() == "Second" )
    {
        ui->mainArea->setCurrentIndex(1);
    }
}
