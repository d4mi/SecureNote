#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

namespace Common
{
/**
 * @brief The NonCopyable class is used to ensure that derived class cannot be copied.
 * Private copy constructor and private copy assignment prevent objects of a class from
 * being copied.
 */
class NonCopyable
{
protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
private:
    NonCopyable( const NonCopyable& ) = delete;
    NonCopyable& operator=(const NonCopyable& ) = delete;
};

}

#endif // NONCOPYABLE_H
