#include "SecurityTest.h"
#include "Security/HexUtils.h"

TEST_F(SecurityTest, FirstTest)
{
	std::string result = "f58c4c04d6e5f1ba779eabfb5f7bfbd6";

	Security::HexUtils hexUtils;
	Security::SecureData iv         = hexUtils.StringToHex("000102030405060708090A0B0C0D0E0F");
	Security::SecureData key        = hexUtils.StringToHex("603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4");
	Security::SecureData testVector = hexUtils.StringToHex("6bc1bee22e409f96e93d7e117393172a");

	Security::SecureData data = m_cryptoOpenSSL.EncryptWithAes256(testVector, key, iv);
	std::string cipherText    = hexUtils.HexToString(data);

    std::cout <<  cipherText.length() << std::endl;

    ASSERT_THAT(cipherText, result);
}

TEST_F(SecurityTest, SecondTest)
{
	std::string result = "e35a6dcb19b201a01ebcfa8aa22b5759";

	Security::HexUtils hexUtils;
	Security::SecureData iv         = hexUtils.StringToHex("00000000000000000000000000000000");
	Security::SecureData key        = hexUtils.StringToHex("8000000000000000000000000000000000000000000000000000000000000000");
	Security::SecureData testVector = hexUtils.StringToHex("00000000000000000000000000000000");

	Security::SecureData data = m_cryptoOpenSSL.EncryptWithAes256(testVector, key, iv);
	std::string cipherText    = hexUtils.HexToString(data);

    std::cout <<  cipherText.length() << std::endl;

    ASSERT_THAT(cipherText, result);
}

TEST_F(SecurityTest, ThirdTest)
{
	std::string result = "9cfc4e967edb808d679f777bc6702c7d";

	Security::HexUtils hexUtils;
	Security::SecureData iv         = hexUtils.StringToHex("F58C4C04D6E5F1BA779EABFB5F7BFBD6");
	Security::SecureData key        = hexUtils.StringToHex("603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4");
	Security::SecureData testVector = hexUtils.StringToHex("ae2d8a571e03ac9c9eb76fac45af8e51");

	Security::SecureData data = m_cryptoOpenSSL.EncryptWithAes256(testVector, key, iv);
	std::string cipherText    = hexUtils.HexToString(data);

    std::cout <<  cipherText.length() << std::endl;

    ASSERT_THAT(cipherText, result);
}

/*
TEST_F(SecurityTest, FourthTest)
{
	std::string result = "9cfc4e967edb808d679f777bc6702c7d";

	Security::HexUtils hexUtils;
	Security::SecureData iv         = hexUtils.StringToHex("F58C4C04D6E5F1BA779EABFB5F7BFBD6");
	Security::SecureData key        = hexUtils.StringToHex("603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4");
	Security::SecureData testVector = hexUtils.StringToHex("ae2d8a571e03ac9c9eb76fac45af8e51");

	Security::SecureData encryptedData = m_cryptoOpenSSL.EncryptWithAes256(testVector, key, iv);
	
	Security::SecureData decryptedData = m_cryptoOpenSSL.DecryptWithAes256(encryptedData, key, iv);

    ASSERT_THAT(encryptedData, ContainerEq(decryptedData));
} 
*/