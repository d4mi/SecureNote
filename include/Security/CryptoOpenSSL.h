#ifndef __CRYPTO_OPEN_SSL_H__
#define __CRYPTO_OPEN_SSL_H__

#include <string>
#include "Security/ICrypto.h"

namespace Security
{

/**
* The CryptoOpenSSL provides common cryptographic ciphers and hashes methods.
* It uses OpenSSL to perform those operations.
*/
class CryptoOpenSSL : ICrypto
{
public:
	CryptoOpenSSL();

	virtual SecureData EncryptWithAes256(const SecureData& input, const SecureData& key, const SecureData& iv);
	virtual SecureData EncryptWithDes(const std::string& input);

private:
	void m_Init();
};

} // namespace Security

#endif // __CRYPTO_OPEN_SSL_H__