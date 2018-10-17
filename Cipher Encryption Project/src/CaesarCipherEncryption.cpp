#include "CaesarCipherEncryption.h"

std::string CaesarCipherEncryption::getEncryptionKey()
{
	return "2x2";
}

std::string *CaesarCipherEncryption::encrypt(std::string *message)
{
	std::string *output = new std::string;
	for (char &letter : *message)
	{
		output->push_back(letter + 5);
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *CaesarCipherEncryption::decrypt(std::string *message)
{
	std::string *output = new std::string;
	for (char &letter : *message)
	{
		output->push_back(letter - 5);
	}
	return output;
}