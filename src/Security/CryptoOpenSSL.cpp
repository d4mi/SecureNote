#include "Security/CryptoOpenSSL.h"
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <memory>

#include <iostream>
#include "Security/HexUtils.h"


namespace Security
{

CryptoOpenSSL::CryptoOpenSSL()
{
	m_Init();
}

SecureData CryptoOpenSSL::EncryptWithAes256(const SecureData& input, const SecureData& key, const SecureData& iv)
{
	SecureData data;

	unsigned char *keyChars  = const_cast<unsigned char*>(&key.front());
	unsigned char *ivChars   = const_cast<unsigned char*>(&iv.front());
	unsigned char *plaintext = const_cast<unsigned char*>(&input.front());

  unsigned int outputSize = input.size() + ((32 - (input.size() % 32)));
  std::unique_ptr<unsigned char[]> ciphertext(new unsigned char[outputSize]);

  int len, ciphertext_len;

  EVP_CIPHER_CTX *ctx;

  if(!(ctx = EVP_CIPHER_CTX_new()))
  {
    return data;
  } 	

  if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, keyChars, ivChars))
  {
    	return data;
  }

  size_t plain_size = strlen((const char*)plaintext);
  if(1 != EVP_EncryptUpdate(ctx, ciphertext.get(), &len, plaintext, plain_size))
  {
    return data;
  }

  	ciphertext_len = len;


	if(1 != EVP_EncryptFinal_ex(ctx, ciphertext.get() + len, &len))
		return data;

  	ciphertext_len += len;

        std::cout << "Input size: " << input.size() << std::endl;
    std::cout << "Length: " << ciphertext_len << std::endl;

 	 /* Clean up */
  	EVP_CIPHER_CTX_free(ctx);

  	data.assign(ciphertext.get(), ciphertext.get() + outputSize);

	return data;
}

SecureData CryptoOpenSSL::EncryptWithDes(const std::string& input)
{
	SecureData data;
	return data;
}

void CryptoOpenSSL::m_Init()
{
	ERR_load_crypto_strings();
	OpenSSL_add_all_algorithms();
	OPENSSL_config(NULL);
}

}; // namespace Security