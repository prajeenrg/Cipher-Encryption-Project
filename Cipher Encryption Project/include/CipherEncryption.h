#pragma once
#include <string>

class CipherEncryption
{
  public:
	virtual ~CipherEncryption() {}
	virtual std::string getEncryptionKey() = 0;
	virtual std::string *encrypt(std::string *) = 0;
	virtual std::string *decrypt(std::string *) = 0;
};

enum class CipherType {
	BITWISE,
	BLOCK,
	CAESAR,
	STREAM,
	TRANSPOSE,
	VIGENERE,
	XOR
};