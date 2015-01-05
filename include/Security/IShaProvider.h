#ifndef I_SHA_PROVIDER
#define I_SHA_PROVIDER

#include <string>

namespace Security
{

class IShaProvider
{
public:
    virtual ~IShaProvider() = default;
    virtual std::string CreateSha256(const std::string& data) const = 0;
};

}

#endif
