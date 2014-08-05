#include "Security/CryptoOpenSSL.h"
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/aes.h>
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

	unsigned char *keyChars  = const_cast<unsigned char*>( &key.front()   );
	unsigned char *ivChars   = const_cast<unsigned char*>( &iv.front()    );
	unsigned char *plaintext = const_cast<unsigned char*>( &input.front() );

  unsigned int inputSize = input.size();
  unsigned int outputSize = input.size() + AES_BLOCK_SIZE;
  std::unique_ptr<unsigned char[]> ciphertext( new unsigned char[outputSize] );

  std::shared_ptr<EVP_CIPHER_CTX> ctx( EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free );

  if( !ctx.get() )
  {
    return data;
  } 	

  int encryptResult = EVP_EncryptInit_ex(ctx.get(), EVP_aes_256_cbc(), NULL, keyChars, ivChars);
  if( 1 != encryptResult )
  {
    	return data;
  }

  int partLength = 0;
  int ciphertextLength = 0;  
  
  if(1 != EVP_EncryptUpdate(ctx.get(), ciphertext.get(), &partLength, plaintext, inputSize))
  {
    return data;
  }

  ciphertextLength = partLength;


	if(1 != EVP_EncryptFinal_ex(ctx.get(), ciphertext.get() + partLength, &partLength))
  {
		return data;
  }

  ciphertextLength += partLength;

  std::cout << "inputSize: " << inputSize  << std::endl;
  std::cout << "Block size: " << EVP_CIPHER_block_size(EVP_aes_256_cbc())  << std::endl;
  std::cout << "Input size: " << input.size() << std::endl;
  std::cout << "Length: " << ciphertextLength << std::endl;

  data.assign(ciphertext.get(), ciphertext.get() + outputSize);

	return data;
}

SecureData CryptoOpenSSL::DecryptWithAes256(const SecureData& input, const SecureData& key, const SecureData& iv)
{
  SecureData decryptedData;

  unsigned char *keyChars  = const_cast<unsigned char*>(&key.front());
  unsigned char *ivChars   = const_cast<unsigned char*>(&iv.front());
  unsigned char *ciphertext = const_cast<unsigned char*>(&input.front());

  EVP_CIPHER_CTX *ctx;

  int len;

  int plaintext_len;

  unsigned char *plaintext = NULL;

  if( !(ctx = EVP_CIPHER_CTX_new()) )
  {
    return decryptedData;
  }

  if( 1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, keyChars, ivChars) )
  {
    return decryptedData;
  }

  if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, input.size()))
  {
    return decryptedData;
  }

  plaintext_len = len;


  if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
  {
    return decryptedData;
  }

  plaintext_len += len;

  
  EVP_CIPHER_CTX_free(ctx);

  decryptedData.assign(plaintext, plaintext + plaintext_len);
  return decryptedData;

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
