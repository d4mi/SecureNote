#include "Model/User.h"

namespace Model
{

User::User()
{

}

User::User(const std::string &username) :
    m_username(username)
{

}

User::~User()
{

}

void User::SetUsername(const std::string &username)
{
    m_username = username;
}

std::string User::GetUsername() const
{
    return m_username;
}

}
