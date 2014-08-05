#ifndef USER_H
#define USER_H

#include <string>

namespace Model
{

class User
{
public:
    User();
    User(const std::string& username);
    ~User();

    void SetUsername(const std::string& username);
    std::string GetUsername() const;

private:
    std::string m_username;

};

} // namespace Model

#endif // USER_H
