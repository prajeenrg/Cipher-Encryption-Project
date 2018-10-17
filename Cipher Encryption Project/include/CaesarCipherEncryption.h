#pragma once
#include "CipherEncryption.h"

class CaesarCipherEncryption : public CipherEncryption
{
  public:
	std::string getEncryptionKey() override;
	std::string *encrypt(std::string *) override;
	std::string *decrypt(std::string *) override;
};