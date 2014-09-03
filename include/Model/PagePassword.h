#ifndef PAGEPASSWORD_H
#define PAGEPASSWORD_H

#include <string>

namespace Model
{

/**
 * @brief The PagePassword class provides a data model for stored password.
 */
class PagePassword
{
public:
    PagePassword();

    /**
     * @brief Returns the password.
     * @return password
     */
    std::string Password() const;

    /**
     * @brief Returns the URL related with saved password.
     * @return url
     */
    std::string Url() const;

    /**
     * @brief Returns the title.
     * @return title
     */
    std::string Title() const;

    /**
     * @brief Returns the description which contains additional information about
     * saved password e.g. user's notes.
     * @return description
     */
    std::string Description() const;

    /**
     * @brief Sets the password.
     * @param password
     */
    void SetPassword(const std::string& password);

    /**
     * @brief Sets the url.
     * @param url
     */
    void SetUrl(const std::string& url);

    /**
     * @brief Sets the title.
     * @param title
     */
    void SetTitle(const std::string& title);

    /**
     * @brief Sets the description
     * @param description
     */
    void SetDescription(const std::string& description);

private:
    std::string m_password;
    std::string m_url;
    std::string m_title;
    std::string m_description;
};

}

#endif // PAGEPASSWORD_H
