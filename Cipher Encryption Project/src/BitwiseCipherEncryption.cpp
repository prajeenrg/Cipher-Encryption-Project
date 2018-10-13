#include "BitwiseCipherEncryption.h"

std::string BitwiseCipherEncryption::getEncryptionKey()
{
	return "0x0";
}

std::string *BitwiseCipherEncryption::encrypt(std::string &message)
{
	std::string *output = new std::string;
	for (char &letter : message)
	{
		output->push_back(~letter);
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *BitwiseCipherEncryption::decrypt(std::string &cipher)
{
	std::string *output = new std::string;
	for (char &letter : cipher)
	{
		output->push_back(~letter);
	}
	return output;
}