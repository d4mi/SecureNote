#include "Security/HexUtils.h"
#include <sstream>

namespace Security
{

SecureData HexUtils::StringToHex(const std::string& inputString) const
{
	SecureData outputHex;
	std::istringstream hexStream(m_AddSpaces(inputString));

	unsigned int singleCharacter;
	while( hexStream >> std::hex >> singleCharacter)
	{
		outputHex.push_back(
			static_cast<unsigned char>(singleCharacter));
	}

	return outputHex;
}

std::string HexUtils::m_AddSpaces(const std::string& input) const
{
	std::string spacedHex = input;
	for(int i = spacedHex.length(); i > 0; i-=2)
	{
		spacedHex.insert(i, 1, ' ');
	} 

	return spacedHex;
}

std::string HexUtils::HexToString(const SecureData& secureData) const
{
	std::ostringstream output;

	for(SecureData::const_iterator it = secureData.cbegin(); it != secureData.cend(); ++it)
	{
		output << std::hex << static_cast<int>(*it);
	}

	return output.str();
}

} // namespace Security
