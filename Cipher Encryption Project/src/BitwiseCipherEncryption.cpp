#include "BitwiseCipherEncryption.h"

std::string BitwiseCipherEncryption::getEncryptionKey()
{
	return "0x0";
}

std::string *BitwiseCipherEncryption::processText(std::string *input)
{
	std::string *output = new std::string;
	for (char &letter : *input)
	{
		output->push_back(~letter);
	}
	return output;
}

std::string *BitwiseCipherEncryption::encrypt(std::string *message)
{
	std::string *output = processText(message);
	output->append(getEncryptionKey());
	return output;
}

std::string *BitwiseCipherEncryption::decrypt(std::string *cipher)
{
	return processText(cipher);
}