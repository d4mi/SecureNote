#include "WebCapture/WebScreenshoter.h"
#include <qt5/QtWebKit/QtWebKit>
#include <qt5/QtCore/QUrl>
#include <QDebug>


WebScreenshoter::WebScreenshoter() :
    m_screenshotSize(1024, 768)
{
    connect(&m_page, SIGNAL(loadProgress(int)), this, SLOT(onProgress(int)));
    connect(&m_page, SIGNAL(loadFinished(bool)), this, SLOT(onFinished(bool)));
}

void WebScreenshoter::LoadPage(const QString& urlString)
{
    QUrl url(urlString);
    m_page.setViewportSize(QSize(1024, 768));
    m_page.mainFrame()->load(url);
    m_page.mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    m_page.mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
}

void WebScreenshoter::SetSize(const QSize &size)
{
    m_screenshotSize = size;
}

void WebScreenshoter::onProgress(int percent)
{
    qDebug() << "Loading page progress: " << percent;
    emit progress(percent);
}

void WebScreenshoter::onFinished(bool ok)
{
    qDebug() << "Loading page finished";
    if( ok )
    {
        SaveFrame(m_page.mainFrame());
    }
    else
    {
        qDebug() << "Error occurred during loading the image";
    }
}

bool WebScreenshoter::SaveFrame(QWebFrame *frame)
{
    bool result = false;

    if( frame )
    {
        QImage image(frame->contentsSize(), QImage::Format_ARGB32_Premultiplied);
        image.fill(Qt::transparent);

        QPainter painter(&image);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setRenderHint(QPainter::TextAntialiasing, true);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        frame->documentElement().render(&painter);
        painter.end();
        image.copy(0,0, m_screenshotSize.width(), m_screenshotSize.height())
                .save("/home/xxx/file.png");

        result = true;
    }

    return result;
}
