#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qt5/QtWidgets/QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
public:
    Q_OBJECT
public:
    MainWindow();

private slots:
    void on_actionClose_triggered();

private:
    Ui::MainWindow *m_mainWindow;

};

#endif // MAINWINDOW_H
