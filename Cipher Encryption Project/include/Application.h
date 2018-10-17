#pragma once
#include <ctime>
#include <Windows.h>

#include "CipherEncryption.h"
#include "BitwiseCipherEncryption.h"
#include "BlockCipherEncryption.h"
#include "CaesarCipherEncryption.h"
#include "FileUtils.h"
#include "TransposeCipherEncryption.h"
#include "XorCipherEncryption.h"
#include "VigenereCipherEncryption.h"
#include "StreamCipherEncryption.h"
#include "Utils.h"

class Application
{
	WORD wAttrs;
	HANDLE hnd;
	int getMainMenuChoice();
	int getEncryptionChoice();
	void showMainScreen();
	int retrieveMenuChoice(std::string, std::string [], int);
	int getInputChoice();
	std::string getFileInfo();
	std::string getSaveFileInfo();
	std::string *getInputInfo();
	CipherEncryption *getSuitableCipher(int);
	void manageEncryption();
	void showEncryptedMessage(std::string *);
	void manageDecryption();
	void showDecryptedCipher(std::string *);
	void showEndCredits();
	void saveInfoToFile(std::string *);

  public:
	Application();
	void runApp();
};