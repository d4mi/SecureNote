#ifndef NOTESBROWSERFORM_H
#define NOTESBROWSERFORM_H

#include <QWidget>

namespace Ui {
class NotesBrowserForm;
}

class NotesBrowserForm : public QWidget
{
    Q_OBJECT

public:
    explicit NotesBrowserForm(QWidget *parent = 0);
    ~NotesBrowserForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NotesBrowserForm *ui;
};

#endif // NOTESBROWSERFORM_H
