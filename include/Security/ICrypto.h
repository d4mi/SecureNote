#ifndef __I_CRYPTPO_H__
#define __I_CRYPTPO_H__

#include <string>
#include "Security/SecureData.h"

namespace Security 
{

/**
* The ICrypto provides interface for cryptographic function. 
*/
class ICrypto 
{
public:
	virtual SecureData EncryptWithAes256(const SecureData& input, const SecureData& key, const SecureData& iv) = 0;
	virtual SecureData DecryptWithAes256(const SecureData& input, const SecureData& key, const SecureData& iv) = 0;
	virtual SecureData EncryptWithDes(const std::string& input) = 0;
};

} // namespace Security

#endif // __I_CRYPTPO_H__
