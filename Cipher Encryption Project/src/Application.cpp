#include "Application.h"

Application::Application() {
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

int Application::getEncryptionChoice()
{
	std::string title = "Choose any one from the following ciphers to proceed : ";
	std::string options[] = { "Bitwise", "Block", "Caesar", "Stream", "Transpose", "Vigenere", "Xor" };
	return retrieveMenuChoice(title, options, 7);
}

int Application::getMainMenuChoice()
{
	std::string title = "What can I do for you ?";
	std::string options[] = { "Encryption", "Decryption", "Quit Program" };
	return retrieveMenuChoice(title, options, 3);
}

int Application::getInputChoice()
{
	std::string title = "How are you going to enter the information ?";
	std::string options[] = { "Type it in console", "Get it from a file" };
	return retrieveMenuChoice(title, options, 2);
}

int Application::getCursorPos(int length)
{
	return static_cast<int>((SCREEN_WIDTH + length) / 2);
}

std::string *Application::getInputInfo()
{
	int inputForm = getInputChoice();
	std::string *input;
	std::cout << std::endl;
	setCursorVisiblity(true);
	if (inputForm == 0)
	{
		input = new std::string;
		std::cout << "Please end your message with a backtick symbol (`)\n";
		std::getline(std::cin, *input, '`');
	}
	else
	{
		std::string fileloc = getFileInfo();
		FileUtils file;
		input = file.readFromFile(fileloc);
		while (input == nullptr)
		{
			std::cout << "\nThe file requested is not accessible. Try again.\n";
			fileloc = getFileInfo();
			input = file.readFromFile(fileloc);
		}
	}
	setCursorVisiblity(false);
	return input;
}

std::string Application::getFileInfo()
{
	std::string filedir;
	std::cout << "What is the complete file path ? ";
	std::getline(std::cin, filedir);
	return filedir;
}

std::string Application::getSaveFileInfo()
{
	std::string filedir;
	std::cout << "What should be the file path ? ";
	std::getline(std::cin, filedir);
	return filedir;
}

CipherEncryption *Application::getSuitableCipher(int options)
{
	CipherEncryption *cipher;
	CipherType type = static_cast<CipherType>(options);
	switch (type)
	{
	case CipherType::BITWISE:
		cipher = new BitwiseCipherEncryption;
		break;
	case CipherType::BLOCK:
	{
		std::string key = "<&Programming is real fun&/>";
		cipher = new BlockCipherEncryption(key);
		break;
	}
	case CipherType::CAESAR:
		cipher = new CaesarCipherEncryption;
		break;
	case CipherType::STREAM:
		cipher = new StreamCipherEncryption;
		break;
	case CipherType::TRANSPOSE:
		cipher = new TransposeCipherEncryption;
		break;
	case CipherType::VIGENERE:
		cipher = new VigenereCipherEncryption;
		break;
	case CipherType::XOR:
	{
		char key = static_cast<char>(27);
		cipher = new XorCipherEncryption(key);
	}
	default:
		return nullptr;
	}
	return cipher;
}

void Application::showMainScreen()
{
	srand(static_cast<unsigned int>(time(NULL)));
	while (true) {
		std::system("cls");
		WORD wAttrs = rand() % 14 + 1;
		SetConsoleTextAttribute(handle, wAttrs);
		std::cout << R"(
        
      /$$$$$$  /$$           /$$
     /$$__  $$|__/          | $$
    | $$  \__/ /$$  /$$$$$$ | $$$$$$$   /$$$$$$   /$$$$$$
    | $$      | $$ /$$__  $$| $$__  $$ /$$__  $$ /$$__  $$
    | $$      | $$| $$  \ $$| $$  \ $$| $$$$$$$$| $$  \__/
    | $$    $$| $$| $$  | $$| $$  | $$| $$_____/| $$
    |  $$$$$$/| $$| $$$$$$$/| $$  | $$|  $$$$$$$| $$
     \______/ |__/| $$____/ |__/  |__/ \_______/|__/
                  | $$
                  | $$
                  |__/
     /$$$$$$$$                                                     /$$     /$$
    | $$_____/                                                    | $$    |__/
    | $$       /$$$$$$$   /$$$$$$$  /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$   /$$  /$$$$$$  /$$$$$$$
    | $$$$$   | $$__  $$ /$$_____/ /$$__  $$| $$  | $$ /$$__  $$|_  $$_/  | $$ /$$__  $$| $$__  $$
    | $$__/   | $$  \ $$| $$      | $$  \__/| $$  | $$| $$  \ $$  | $$    | $$| $$  \ $$| $$  \ $$
    | $$      | $$  | $$| $$      | $$      | $$  | $$| $$  | $$  | $$ /$$| $$| $$  | $$| $$  | $$
    | $$$$$$$$| $$  | $$|  $$$$$$$| $$      |  $$$$$$$| $$$$$$$/  |  $$$$/| $$|  $$$$$$/| $$  | $$
    |________/|__/  |__/ \_______/|__/       \____  $$| $$____/    \___/  |__/ \______/ |__/  |__/
                                             /$$  | $$| $$
                                            |  $$$$$$/| $$
                                             \______/ |__/
     /$$$$$$$                                               /$$
    | $$__  $$                                             | $$
    | $$  \ $$ /$$$$$$   /$$$$$$  /$$  /$$$$$$   /$$$$$$$ /$$$$$$
    | $$$$$$$//$$__  $$ /$$__  $$|__/ /$$__  $$ /$$_____/|_  $$_/
    | $$____/| $$  \__/| $$  \ $$ /$$| $$$$$$$$| $$        | $$
    | $$     | $$      | $$  | $$| $$| $$_____/| $$        | $$ /$$
    | $$     | $$      |  $$$$$$/| $$|  $$$$$$$|  $$$$$$$  |  $$$$/
    |__/     |__/       \______/ | $$ \_______/ \_______/   \___/
                            /$$  | $$
                           |  $$$$$$/  
                            \______/

        )" << std::endl;
		std::cout << std::setw(getCursorPos(31)) << "Press Enter to Continue........";
		if (GetAsyncKeyState(VK_RETURN)) {
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN_BRIGHT);
			return;
		}
		Sleep(SLEEP_DURATION);
	}
}

void Application::setWindowSize(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Application::setCursorVisiblity(bool isVisible)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = isVisible;
	SetConsoleCursorInfo(handle, &cursorInfo);
}

int Application::retrieveMenuChoice(std::string title, std::string choices[], int size)
{
	int pointer = 0;
	while (true) {
		std::system("cls");
		std::cout << std::string(SCREEN_WIDTH, '*') << std::endl;
		std::cout << std::setw(getCursorPos(25)) << "Cipher Encryption Project" << std::endl;
		std::cout << std::string(SCREEN_WIDTH, '*') << std::endl;
		std::cout << title << std::endl;
		for (int i = 0; i != size; i++) {
			std::cout << "  ";
			if (i == pointer) {
				SetConsoleTextAttribute(handle, FOREGROUND_PURPLE_BRIGHT);
				std::cout << "->";
			}
			std::cout << (i + 1) << ") " << choices[i] << std::endl;
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN_BRIGHT);
		}
		while (true) {
			std::system("pause>nul");
			if (GetAsyncKeyState(VK_UP)) {
				pointer--;
				if (pointer < 0) {
					pointer = size - 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN)) {
				pointer++;
				if (pointer == size) {
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN)) {
				return pointer;
			}
			Sleep(SLEEP_DURATION);
		}
	}
}

void Application::saveInfoToFile(std::string *content)
{
	std::cin.ignore();
	std::string filedir = getSaveFileInfo();
	FileUtils file;
	file.writeToFile(filedir, content);
	std::cout << "Voila! The file has been saved.";
	std::system("pause>nul");
}

void Application::manageEncryption()
{
	int encryptionChoice = getEncryptionChoice();
	std::cout << std::endl;
	std::string *message = getInputInfo();
	CipherEncryption *cipher = getSuitableCipher(encryptionChoice);
	std::string *encrypted = cipher->encrypt(message);
	delete message;
	char choice;
	setCursorVisiblity(true);
	std::cout << "\nDo you want to see encrypted message (Y/n) ? ";
	std::cin >> choice;
	if (tolower(choice) == 'y')
	{
		std::cout << "\nThe information has been encrypted to the following :\n";
		std::cout << encrypted->c_str() << std::endl;
	}
	std::cout << "\nDo you want to save encrypted message (Y/n) ? ";
	std::cin >> choice;
	if (tolower(choice) == 'y')
	{
		std::cout << std::endl;
		saveInfoToFile(encrypted);
	}
	setCursorVisiblity(false);
	delete encrypted;
	delete cipher;
}

void Application::manageDecryption()
{
	std::string *message = getInputInfo();
	std::string key = message->substr(message->size() - 3);
	std::regex match_key(R"(([0-6])x\1)");
	*message = message->substr(0, message->size() - 3);
	if (message->empty()) {
		std::cout << "\nThe cipher text doesn't contain any information (-_-) .";
		std::system("pause>nul");
		delete message;
		return;
	}
	CipherEncryption *cipher = getSuitableCipher(key[0] - '0');
	if (!std::regex_match(key, match_key) || !cipher)
	{
		std::cout << "\nThere is no suitable cipher available for decryption.";
		std::system("pause>nul");
		delete message;
		return;
	}
	std::string *decrypted = cipher->decrypt(message);
	delete message;
	char choice;
	setCursorVisiblity(true);
	std::cout << "\nDo you want to see decrypted message (Y/n) ? ";
	std::cin >> choice;
	if (tolower(choice) ==  'y')
	{
		std::cout << "\nThe given information has been decrypted to the following :\n";
		std::cout << decrypted->c_str() << std::endl;
	}
	std::cout << "\nDo you want to save decrypted message (Y/n) ?";
	std::cin >> choice;
	if (tolower(choice) == 'y')
	{
		std::cout << std::endl;
		saveInfoToFile(decrypted);
	}
	setCursorVisiblity(false);
	delete decrypted;
}

void Application::showEndCredits()
{
	std::system("cls");
	std::string title = "Project done by the following students of XII - A :";
	std::string decoration(SCREEN_WIDTH, '*');
	std::cout << decoration << std::endl;
	std::cout << std::setw(getCursorPos(51)) << title << std::endl;
	std::cout << decoration << std::endl;
	std::cout << "\n\n\n";
	std::cout << std::setw(getCursorPos(28)) << "Abhishek Sriram, Roll No : 2" << std::endl;
	std::cout << std::setw(getCursorPos(27)) << "Ashwin Kumar M, Roll No : 3" << std::endl;
	std::cout << std::setw(getCursorPos(25)) << "Prajeen R G, Roll No : 20" << std::endl;
	std::cout << std::setw(getCursorPos(22)) << "Vishal B, Roll No : 40";
}

void Application::runApp()
{
	setWindowSize(SCREEN_WIDTH * CHARACTER_WIDTH, SCREEN_HEIGHT * CHARACTER_HEIGHT);
	setCursorVisiblity(false);
	showMainScreen();
	do
	{
		std::system("cls");
		int menuChoice = getMainMenuChoice();
		std::cout << std::endl;
		if (menuChoice == 0) {
			manageEncryption();
		}
		else if (menuChoice == 1) {
			manageDecryption();
		}
		else {
			break;
		}
	} while (true);
	std::system("cls");
	showEndCredits();
	std::system("pause>nul");
}