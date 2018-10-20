#pragma once
#include "CipherEncryption.h"

class StreamCipherEncryption : public CipherEncryption
{
	std::string *processText(std::string *);
  public:
	std::string getEncryptionKey() override;
	std::string *encrypt(std::string *) override;
	std::string *decrypt(std::string *) override;
};