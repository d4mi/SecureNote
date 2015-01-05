#ifndef __HEX_UTILS_H__
#define __HEX_UTILS_H__

#include <string>
#include "Security/SecureData.h"

namespace Security
{

class HexUtils 
{
public:
	SecureData StringToHex(const std::string& inputString) const;
	std::string HexToString(const SecureData& secureData) const;
    std::string HexToString(const unsigned char* secureData, const size_t size) const;

private:
	std::string m_AddSpaces(const std::string& input) const;

};

} // namespace Security

#endif // __HEX_UTILS_H__
