#ifndef WEBSCREENSHOTER_H
#define WEBSCREENSHOTER_H

#include <string>
#include <QObject>
#include <qt5/QtWebKitWidgets/QtWebKitWidgets>
#include <qt5/QtCore/QString>

class WebScreenshoter : public QObject
{
    Q_OBJECT

public:
    WebScreenshoter();

    void LoadPage(const QString& urlString);
    void SetSize(const QSize& size);

signals:
    void progress(int progress);

private slots:
    void onProgress(int percent);
    void onFinished(bool ok);

private:
    bool SaveFrame(QWebFrame *frame);
    QWebPage m_page;
    QSize m_screenshotSize;

};

#endif // WEBSCREENSHOTER_H
