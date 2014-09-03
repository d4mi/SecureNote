#ifndef PASSWORDNOTEFORM_H
#define PASSWORDNOTEFORM_H

#include <QWidget>
#include <memory>

class WebScreenshoter;

namespace Ui {
class PasswordNoteForm;
}

class PasswordNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordNoteForm(QWidget *parent = 0);
    ~PasswordNoteForm();

private slots:
    void on_pushButton_clicked();
    void onLoadPageFinished();

private:
    void Init();

private:
    Ui::PasswordNoteForm *ui;
    std::shared_ptr<WebScreenshoter> webScreenshoter;


};

#endif // PASSWORDNOTEFORM_H
