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
    ~MainWindow();

private slots:
    void on_actionClose_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
