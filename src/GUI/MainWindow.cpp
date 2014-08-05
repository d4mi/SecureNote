#include "GUI/MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow()
    : m_mainWindow(new Ui::MainWindow)
{
    m_mainWindow->setupUi(this);
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}
