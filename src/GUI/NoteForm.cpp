#include "GUI/NoteForm.h"
#include "ui_NoteForm.h"

#include "QMessageBox"

NoteForm::NoteForm(QWidget* parent)
    : ui(new Ui::NoteForm),
      QWidget(parent)
{
    ui->setupUi(this);
}

NoteForm::~NoteForm()
{
    QMessageBox::warning(this, "Hello", "REMOVED");
    delete ui;
}
