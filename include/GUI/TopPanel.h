#ifndef TOPPANEL_H
#define TOPPANEL_H

#include <QWidget>

namespace Ui {
class TopPanel;
}

class TopPanel : public QWidget
{
    Q_OBJECT

public:
    explicit TopPanel(QWidget *parent = 0);
    ~TopPanel();

private:
    Ui::TopPanel *ui;
};

#endif // TOPPANEL_H
