#include "GUI/PasswordNoteForm.h"
#include "ui_PasswordNoteForm.h"

#include <qt5/QtGui/QPixmap>
#include "WebCapture/WebScreenshoter.h"

PasswordNoteForm::PasswordNoteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordNoteForm),
    webScreenshoter(new WebScreenshoter)
{
    ui->setupUi(this);
    Init();

    connect(webScreenshoter.get(), SIGNAL(finished(bool)), this, SLOT(onLoadPageFinished()));
}

PasswordNoteForm::~PasswordNoteForm()
{
    delete ui;
}

void PasswordNoteForm::Init()
{
    QPixmap itemImage("/home/xxx/pass.png");
    ui->itemImage->setPixmap(itemImage);
}

void PasswordNoteForm::on_pushButton_clicked()
{
    webScreenshoter->LoadPage(ui->lineEdit->text());
}

void PasswordNoteForm::onLoadPageFinished()
{
    QPixmap itemImage = QPixmap::fromImage( webScreenshoter->GetScreenshot());
    ui->itemImage->setPixmap( itemImage );
}
