#ifndef WEBSCREENSHOTER_H
#define WEBSCREENSHOTER_H

#include <string>
#include <QObject>

class WebScreenshoter : public QObject
{
    Q_OBJECT

public:
    WebScreenshoter();

    void LoadPage(const std::string& url);

private:
    //QWebPage page;

};

#endif // WEBSCREENSHOTER_H
