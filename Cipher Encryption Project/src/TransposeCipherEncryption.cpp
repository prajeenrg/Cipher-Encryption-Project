#include "TransposeCipherEncryption.h"

std::string TransposeCipherEncryption::getEncryptionKey()
{
    return "4x4";
}

std::string *TransposeCipherEncryption::encrypt(std::string *message)
{
	std::string *output = new std::string;
	int blockSize = static_cast<int>(floor(sqrt(message->size()))) + 1;
	for (std::string::size_type i = 0; i < blockSize; i++) {
		for (std::string::size_type j = 0; j < blockSize; j++) {
			std::string::size_type index = (j * blockSize) + i;
			if (index < message->size())
			{
				output->push_back(message->at(index));
			}
			else
			{
				output->push_back(1);
			}

		}
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *TransposeCipherEncryption::decrypt(std::string *cipher)
{
	std::string *output = new std::string;
	int blockSize = static_cast<int>(sqrt(cipher->size()));
	for (std::string::size_type i = 0; i < blockSize; i++) {
		for (std::string::size_type j = 0; j < blockSize; j++) {
			std::string::size_type index = (j * blockSize) + i;
			char ch = cipher->at(index);
			if (ch != 1)
			{
				output->push_back(ch);
			}

		}
	}
	return output;
}