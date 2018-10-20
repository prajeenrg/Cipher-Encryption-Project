#include "TransposeCipherEncryption.h"

std::string TransposeCipherEncryption::getEncryptionKey()
{
    return "4x4";
}

std::string *TransposeCipherEncryption::processText(std::string *input) 
{
	std::string *output = new std::string;
	int blockSize = static_cast<int>(sqrt(input->size())) + 1;
	for (int i = 0; ; i++) 
	{
		int index = i;
		while (index < input->size())
		{
			output->push_back(input->at(index));
			index += blockSize;
		}
		if (index == input->size() + blockSize)
		{
			break;
		}
	}
	return output;
}

std::string *TransposeCipherEncryption::encrypt(std::string *message)
{
	std::string *output = processText(message);
	output->append(getEncryptionKey());
	return output;
}

std::string *TransposeCipherEncryption::decrypt(std::string *cipher)
{
    return processText(cipher);
}