#pragma once
#include <cmath>

#include "CipherEncryption.h"

class TransposeCipherEncryption : public CipherEncryption
{
  public:
    std::string getEncryptionKey() override;
    std::string *encrypt(std::string &) override;
    std::string *decrypt(std::string &) override;
};