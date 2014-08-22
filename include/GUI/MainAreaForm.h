#ifndef MAINAREAFORM_H
#define MAINAREAFORM_H

#include <QStackedWidget>

namespace Ui {
class MainAreaForm;
}

class MainAreaForm : public QStackedWidget
{
    Q_OBJECT

public:
    explicit MainAreaForm(QWidget *parent = 0);
    ~MainAreaForm();

private:
    Ui::MainAreaForm *ui;
};

#endif // MAINAREAFORM_H
