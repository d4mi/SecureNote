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
	std::string result = "46f2fb342d6f0ab477476fc501242c5f";

	Security::HexUtils hexUtils;
	Security::SecureData iv         = hexUtils.StringToHex("00000000000000000000000000000000");
	Security::SecureData key        = hexUtils.StringToHex("c47b0294dbbbee0fec4757f22ffeee3587ca4730c3d33b691df38bab076bc558");
	Security::SecureData testVector = hexUtils.StringToHex("00000000000000000000000000000000");

	Security::SecureData data = m_cryptoOpenSSL.EncryptWithAes256(testVector, key, iv);
	std::string cipherText    = hexUtils.HexToString(data);

    std::cout <<  cipherText.length() << std::endl;

    ASSERT_THAT(cipherText, result);
}