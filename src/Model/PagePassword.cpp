#include "Model/PagePassword.h"

namespace Model
{

PagePassword::PagePassword()
{
}

std::string PagePassword::Password() const
{
    return m_password;
}

std::string PagePassword::Url() const
{
    return m_url;
}

std::string PagePassword::Title() const
{
    return m_title;
}

std::string PagePassword::Description() const
{
    return m_description;
}

void PagePassword::SetPassword(const std::string &password)
{
    m_password = password;
}

void PagePassword::SetUrl(const std::string &url)
{
    m_url = url;
}

void PagePassword::SetTitle(const std::string &title)
{
   m_title = title;
}

void PagePassword::SetDescription(const std::string &description)
{
    m_description = description;
}

}
