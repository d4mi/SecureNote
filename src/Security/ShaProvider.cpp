#include "Security/ShaProvider.h"

#include <sstream>

#include "Security/HexUtils.h"
#include "openssl/sha.h"

namespace Security
{

std::string Security::ShaProvider::CreateSha256(const std::string& data) const
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);

    HexUtils hexUtils;
    std::string shaHash = hexUtils.HexToString(hash, SHA256_DIGEST_LENGTH);

    return shaHash;
}

}
