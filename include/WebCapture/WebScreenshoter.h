#ifndef WEBSCREENSHOTER_H
#define WEBSCREENSHOTER_H

#include <QObject>
#include <qt5/QtWebKitWidgets/QtWebKitWidgets>
#include <qt5/QtCore/QString>
#include <qt5/QtGui/QImage>

#include "WebCapture/IWebScreenshoter.h"

/**
 * @brief The WebScreenshoter class is used for creating web page screenshots.
 */
class WebScreenshoter : public QObject,
                        public IWebScreenshoter
{
    Q_OBJECT

public:
    /**
     * @brief Constructs an empty object.
     */
    WebScreenshoter();

    /**
     * @brief Loads page from given @url and saves image into @output location.
     * @param urlString  - url of the captured page.
     */
    virtual void LoadPage(const QString& urlString);

    /**
    * @brief Saves screenshot of loaded page as an image.
    * @param outputPath - output path where image will be saved.
    * @param outputName - output name of the image
    * @pre This method must be called after receiving @finished signal.
    */
    virtual void SaveImage(const QString& outputPath, const QString& outputName);

    /**
     * @brief Returns QImage object with captured page.
     * @return captured screenshot
     */
    virtual QImage GetScreenshot();

    /**
     * @brief Sets size of output image. The default size of output screenshot is 1024x768.
     * @param size - size of the output sceenshot
     */
    virtual void SetSize(const QSize& size);

signals:
    /**
     * @brief This signal is emitted when progress has changed.
     * @param progress - the current value (0-100)
     */
    void progress(int progress);

    /**
     * @brief This signal is emitted when loading page is completed.
     * @param ok - indicates whether load was successful or any any error occured.
     */
    void finished(bool ok);

private slots:
    /**
     * @brief This slot is called when progress has changed.
     * @param percent - the current value (0-100)
     */
    void onProgress(int percent);

    /**
     * @brief This slot is called when loading page is finished.
     * @param ok - indicates whether load was successful or any error occured
     */
    void onFinished(bool ok);

private:
    /** contains size of output screenshot **/
    QSize m_screenshotSize;

    /** contains path of output directory **/
    QString m_outputPath;

    /** contains name of output file **/
    QString m_outputName;

    /** holds screenshoted page **/
    QWebPage m_page;
};

#endif // WEBSCREENSHOTER_H
