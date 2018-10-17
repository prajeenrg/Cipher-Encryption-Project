#include "BlockCipherEncryption.h"

BlockCipherEncryption::BlockCipherEncryption(std::string &code) : key(code) {}

std::string BlockCipherEncryption::getEncryptionKey() {
	return "1x1";
}

std::string *BlockCipherEncryption::encrypt(std::string *message)
{
	std::string *output = new std::string;
	for (std::string::size_type i = 0; i != message->size(); i++) {
		char encodedValue = (message->at(i) ^ getKey(i)) - getKey(i);
		output->push_back(encodedValue);
	}
	output->append(getEncryptionKey());
	return output;
}

std::string *BlockCipherEncryption::decrypt(std::string *cipher)
{
	std::string *output = new std::string;
	for (std::string::size_type i = 0; i != cipher->size(); i++) {
		char decodeValue = (cipher->at(i) + getKey(i)) ^ getKey(i);
		output->push_back(decodeValue);
	}
	return output;
}

char BlockCipherEncryption::getKey(int pos) {
	return key[pos % key.size()];
}