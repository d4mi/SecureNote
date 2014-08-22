#include "GUI/NotesBrowserForm.h"
#include "ui_NotesBrowserForm.h"

#include "GUI/NoteForm.h"

NotesBrowserForm::NotesBrowserForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotesBrowserForm)
{
    ui->setupUi(this);


}

NotesBrowserForm::~NotesBrowserForm()
{
    delete ui;
}

void NotesBrowserForm::on_pushButton_clicked()
{
    NoteForm *noteForm = new NoteForm();
    noteForm->show();
}
