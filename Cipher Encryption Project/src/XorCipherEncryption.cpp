#include "XorCipherEncryption.h"

XorCipherEncryption::XorCipherEncryption(char &keyCode)
{
	key = keyCode;
}

std::string XorCipherEncryption::getEncryptionKey()
{
	return "6x6";
}

std::string *XorCipherEncryption::encrypt(std::string &message)
{
	std::string *output = new std::string;
	char value = 0;
	for (char &letter : message)
	{
		value = letter ^ key;
		output->push_back(value);
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *XorCipherEncryption::decrypt(std::string &cipher)
{
	std::string *output = new std::string;
	char value = 0;
	for (char &letter : cipher)
	{
		value = letter ^ key;
		output->push_back(value);
	}
	return output;
}