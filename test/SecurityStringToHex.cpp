#include "SecurityTest.h"
#include "Security/HexUtils.h"

TEST_F(SecurityTest, StringToHex_1)
{
	Security::HexUtils hexUtils;
	std::string hexString = "FFFF";

	Security::SecureData bytes = hexUtils.StringToHex(hexString);

	ASSERT_THAT(bytes, ElementsAre(0xFF, 0xFF));
}

TEST_F(SecurityTest, StringToHex_2)
{
	Security::HexUtils hexUtils;
	std::string hexString = "AFFFF";

	Security::SecureData bytes = hexUtils.StringToHex(hexString);

	ASSERT_THAT(bytes, ElementsAre(0x0A, 0xFF, 0xFF));
}

TEST_F(SecurityTest, StringToHex_3)
{
	Security::HexUtils hexUtils;
	std::string hexString = "A";

	Security::SecureData bytes = hexUtils.StringToHex(hexString);

	ASSERT_THAT(bytes, ElementsAre(0x0A));
}

TEST_F(SecurityTest, StringToHex_4)
{
	Security::HexUtils hexUtils;
	std::string hexString = "00000";

	Security::SecureData bytes = hexUtils.StringToHex(hexString);

	ASSERT_THAT(bytes, ElementsAre(0x00, 0x00, 0x00));
}

TEST_F(SecurityTest, StringToHex_5)
{
	int result [] = { 0x6b, 0xc1, 0xbe, 0xe2,
		 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };

	Security::SecureData data(result, result + ( sizeof(result)/sizeof(int) ));

	Security::HexUtils hexUtils;
	std::string hexString = "6bc1bee22e409f96e93d7e117393172a";

	Security::SecureData bytes = hexUtils.StringToHex(hexString);

	ASSERT_THAT(bytes, ContainerEq(data));
}

TEST_F(SecurityTest, HexToString_01)
{
	std::string result = "6bc1bee22e409f96e93d7e117393172a";

	int input [] = { 0x6b, 0xc1, 0xbe, 0xe2,
		 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };

	Security::SecureData data(input, input + ( sizeof(input)/sizeof(int) ));

	Security::HexUtils hexUtils;
	std::string hexString = hexUtils.HexToString(data);

	ASSERT_THAT(hexString, result);
}

TEST_F(SecurityTest, HexToString_02)
{
	std::string result = "";

	int input [] = { };

	Security::SecureData data(input, input + ( sizeof(input)/sizeof(int) ));

	Security::HexUtils hexUtils;
	std::string hexString = hexUtils.HexToString(data);

	ASSERT_THAT(hexString, result);
}

TEST_F(SecurityTest, HexToString_03)
{
	std::string result = "0";

	int input [] = { 0x00 };

	Security::SecureData data(input, input + ( sizeof(input)/sizeof(int) ));

	Security::HexUtils hexUtils;
	std::string hexString = hexUtils.HexToString(data);

	ASSERT_THAT(hexString, result);
}
