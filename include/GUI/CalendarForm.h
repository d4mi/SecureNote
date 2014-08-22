#ifndef CALENDARFORM_H
#define CALENDARFORM_H

#include <QWidget>

namespace Ui {
class CalendarForm;
}

class CalendarForm : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarForm(QWidget *parent = 0);
    ~CalendarForm();

private:
    Ui::CalendarForm *ui;
};

#endif // CALENDARFORM_H
