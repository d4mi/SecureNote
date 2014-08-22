#include "GUI/MainAreaForm.h"
#include "ui_MainAreaForm.h"

MainAreaForm::MainAreaForm(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::MainAreaForm)
{
    ui->setupUi(this);
}

MainAreaForm::~MainAreaForm()
{
    delete ui;
}
