#include "GUI/NoteForm.h"
#include "ui_NoteForm.h"

NoteForm::NoteForm(QWidget* parent)
    : ui(new Ui::NoteForm),
      QWidget(parent)
{
    ui->setupUi(this);
}

NoteForm::~NoteForm()
{
    delete ui;
}
