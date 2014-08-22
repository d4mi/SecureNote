#include "GUI/CalendarForm.h"
#include "ui_CalendarForm.h"

CalendarForm::CalendarForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarForm)
{
    ui->setupUi(this);
}

CalendarForm::~CalendarForm()
{
    delete ui;
}
