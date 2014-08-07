#include "GUI/TopPanel.h"
#include "ui_TopPanel.h"

TopPanel::TopPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopPanel)
{
    ui->setupUi(this);
}

TopPanel::~TopPanel()
{
    delete ui;
}
