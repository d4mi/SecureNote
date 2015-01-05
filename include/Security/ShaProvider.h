#ifndef SHA_PROVIDER
#define SHA_PROVIDER

#include <string>
#include "IShaProvider.h"

namespace Security
{

class ShaProvider : public IShaProvider
{
public:

    ~ShaProvider() = default;
    virtual std::string CreateSha256(const std::string& data) const;
};

}

#endif
