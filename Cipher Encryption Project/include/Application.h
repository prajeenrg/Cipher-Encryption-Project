#pragma once
constexpr auto SCREEN_WIDTH = 105;
constexpr auto SCREEN_HEIGHT = 40;
constexpr auto CHARACTER_WIDTH = 8.5;
constexpr auto CHARACTER_HEIGHT = 15;
constexpr auto FOREGROUND_YELLOW_BRIGHT = 0xE;
constexpr auto FOREGROUND_PURPLE_BRIGHT = 0xD;
constexpr auto SLEEP_DURATION = 200;

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
	int getSpacingProps(int);
	void gotoCenter(int);
	std::string getFileInfo();
	std::string getSaveFileInfo();
	std::string *getInputInfo();
	CipherEncryption *getSuitableCipher(int);
	void manageEncryption();
	void manageDecryption();
	void showEndCredits();
	void saveInfoToFile(std::string *);

  public:
	Application();
	void runApp();
};