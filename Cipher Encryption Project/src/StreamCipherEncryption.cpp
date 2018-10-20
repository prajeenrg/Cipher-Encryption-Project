#include "StreamCipherEncryption.h"

std::string StreamCipherEncryption::getEncryptionKey()
{
	return "3x3";
}

std::string *StreamCipherEncryption::processText(std::string *input)
{
	std::string *output = new std::string;
	for (std::string::size_type i = 1; i < input->size(); i += 2)
	{
		output->push_back(input->at(i));
		output->push_back(input->at(i - 1));
	}
	return output;
}

std::string *StreamCipherEncryption::encrypt(std::string *message)
{
	std::string *output = processText(message);
	output->append(getEncryptionKey());
	return output;
}

std::string *StreamCipherEncryption::decrypt(std::string *cipher)
{
	return processText(cipher);
}