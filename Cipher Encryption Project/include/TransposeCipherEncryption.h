#pragma once
#include <cmath>

#include "CipherEncryption.h"

class TransposeCipherEncryption : public CipherEncryption
{
	std::string *processText(std::string *);
  public:
    std::string getEncryptionKey() override;
    std::string *encrypt(std::string *) override;
    std::string *decrypt(std::string *) override;
};