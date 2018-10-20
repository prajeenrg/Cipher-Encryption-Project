#include "XorCipherEncryption.h"

XorCipherEncryption::XorCipherEncryption(char &keyCode)
{
	key = keyCode;
}

std::string XorCipherEncryption::getEncryptionKey()
{
	return "6x6";
}

std::string *XorCipherEncryption::processText(std::string *input)
{
	std::string *output = new std::string;
	for (char &letter : *input)
	{
		output->push_back(letter ^ key);
	}
	return output;
}

std::string *XorCipherEncryption::encrypt(std::string *message)
{
	std::string *output = processText(message);
	output->append(getEncryptionKey());
	return output;
}

std::string *XorCipherEncryption::decrypt(std::string *cipher)
{
	return processText(cipher);
}