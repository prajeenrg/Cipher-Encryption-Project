#pragma once
#define SCREEN_WIDTH 104
#define SCREEN_HEIGHT 40
#define CHARACTER_WIDTH 8
#define CHARACTER_HEIGHT 14
#define FOREGROUND_GREEN_BRIGHT 0xA
#define FOREGROUND_PURPLE_BRIGHT 0xD
#define SLEEP_DURATION 200

#include <iostream>
#include <iomanip>
#include <ctime>
#include <regex>
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

class Application
{
	HANDLE handle;
	int getMainMenuChoice();
	int getEncryptionChoice();
	void showMainScreen();
	void setWindowSize(int, int);
	void setCursorVisiblity(bool);
	int retrieveMenuChoice(std::string, std::string [], int);
	int getInputChoice();
	std::string getFileInfo();
	std::string getSaveFileInfo();
	std::string *getInputInfo();
	CipherEncryption *getSuitableCipher(int);
	void manageEncryption();
	void manageDecryption();
	// void showEndCredits();
	void saveInfoToFile(std::string *);

  public:
	Application();
	void runApp();
};