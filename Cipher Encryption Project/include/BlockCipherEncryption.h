#pragma once
#include "CipherEncryption.h"

class BlockCipherEncryption : public CipherEncryption
{
	std::string key;

  public:
	BlockCipherEncryption(std::string &);
	std::string getEncryptionKey() override;
	std::string *encrypt(std::string &) override;
	std::string *decrypt(std::string &) override;
	char getKey(int);
};