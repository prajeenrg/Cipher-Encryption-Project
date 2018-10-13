#pragma once
#include <string>

class CipherEncryption
{
  public:
	virtual ~CipherEncryption() {}
	virtual std::string getEncryptionKey() = 0;
	virtual std::string *encrypt(std::string &) = 0;
	virtual std::string *decrypt(std::string &) = 0;
};

enum class CipherType {
	BITWISE = 1,
	BLOCK = 2,
	CAESAR = 3,
	STREAM = 4,
	TRANSPOSE = 5,
	VIGENERE = 6,
	XOR = 7
};