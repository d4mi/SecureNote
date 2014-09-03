#ifndef IWEBSCREENSHOTER_H
#define IWEBSCREENSHOTER_H

#include <qt5/QtCore/QString>
#include <qt5/QtGui/QImage>

/**
 * @brief The IWebScreenshoter class provides common interface for creating web page screenshots.
 */
class IWebScreenshoter
{
public:
    /**
     * @brief Loads page from given @url and saves image into @output location.
     * @param urlString  - url of the captured page.
     */
    virtual void LoadPage(const QString& urlString) = 0;

    /**
    * @brief Saves screenshot of loaded page as an image.
    * @param outputPath - output path where image will be saved.
    * @param outputName - output name of the image
    * @pre This method must be called after receiving @finished signal.
    */
    virtual void SaveImage(const QString& outputPath, const QString& outputName) = 0;

    /**
     * @brief Returns QImage object with captured page.
     * @return captured screenshot
     */
    virtual QImage GetScreenshot() = 0;

    /**
     * @brief Sets size of output image. The default size of output screenshot is 1024x768.
     * @param size - size of the output sceenshot
     */
    virtual void SetSize(const QSize& size) = 0;

};

#endif // IWEBSCREENSHOTER_H
