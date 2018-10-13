#include "VigenereCipherEncryption.h"

std::string VigenereCipherEncryption::getEncryptionKey()
{
	return "4x4";
}

char VigenereCipherEncryption::encodeKeyValue(char value)
{
	char key = 0;
	if (value > 'z')
	{
		key = value;
	}
	else if (value >= 'A' && value <= 'Z')
	{
		key = value - 'A' + 1;
	}
	else if (value >= 'a' && value <= 'z')
	{
		key = 26 + value - 'a' + 1;
	}
	else if (value >= '0' && value <= '9')
	{
		key = 52 + value - '0' + 1;
	}
	else if (value > 'Z')
	{
		key = value + 26;
	}
	else if (value < '0')
	{
		key = value + 62;
	}
	else if (value > '9')
	{
		key = value + 52;
	}
	return key;
}

char VigenereCipherEncryption::decodeKeyValue(char value)
{
	int dekey = 0;
	if (value > 'z')
	{
		dekey = value;
	}
	else if (value >= 1 && value <= 26)
	{
		dekey = value + 'A' - 1;
	}
	else if (value >= 27 && value <= 52)
	{
		dekey = value + 'a' - 27;
	}
	else if (value >= 53 && value <= 62)
	{
		dekey = value + '0' - 53;
	}
	else if (value < 110)
	{
		dekey = value - 62;
	}
	else if (value < 117)
	{
		dekey = value - 52;
	}
	else if (value < 123)
	{
		dekey = value - 26;
	}
	return dekey;
}

std::string *VigenereCipherEncryption::encrypt(std::string &message)
{
	std::string *output = new std::string;
	char value = 0;
	for (char &letter : message)
	{
		value = encodeKeyValue(letter);
		output->push_back(value);
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *VigenereCipherEncryption::decrypt(std::string &cipher)
{
	std::string *output = new std::string;
	char value = 0;
	for (char &letter : cipher)
	{
		value = decodeKeyValue(letter);
		output->push_back(value);
	}
	return output;
}