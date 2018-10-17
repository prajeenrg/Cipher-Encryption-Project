#include "Application.h"

Application::Application() {
	wAttrs = 0;
	hnd = GetStdHandle(STD_OUTPUT_HANDLE);
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

std::string *Application::getInputInfo()
{
	int inputForm = getInputChoice();
	std::string *input;
	if (inputForm == 0)
	{
		input = new std::string;
		std::cout << std::endl;
		std::cout << "\tPlease end your message with a backtick symbol (`)";
		std::cout << std::endl;
		std::getline(std::cin, *input, '`');
	}
	else
	{
		std::cout << std::endl;
		std::string fileloc = getFileInfo();
		FileUtils file;
		input = file.readFromFile(fileloc);
		while (input == nullptr)
		{
			std::cout << std::endl;
			std::cout << "The file requested is not accessible. Try again.";
			std::cout << std::endl;
			fileloc = getFileInfo();
			input = file.readFromFile(fileloc);
		}
	}
	return input;
}

std::string Application::getFileInfo()
{
	std::string filedir, filename;
	std::cout << "Where can I get the file ? ";
	std::getline(std::cin, filedir);
	std::cout << "What is the name of the file ? ";
	std::getline(std::cin, filename);
	if (!filedir.empty())
	{
		filedir.push_back('\\');
	}
	filedir.append(filename);
	return filedir;
}

std::string Application::getSaveFileInfo()
{
	std::string filedir, filename;
	std::cout << "Where should the file be stored ? ";
	std::getline(std::cin, filedir);
	std::cout << "What should be the name of the file ? ";
	std::getline(std::cin, filename);
	if (!filedir.empty())
	{
		filedir.push_back('\\');
	}
	filedir.append(filename);
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
	default:
	{
		char key = static_cast<char>(27);
		cipher = new XorCipherEncryption(key);
	}
	}
	return cipher;
}

void Application::showMainScreen()
{
	srand(static_cast<unsigned int>(time(NULL)));
	while (true) {
		std::system("cls");
		wAttrs = rand() % 14 + 1;
		SetConsoleTextAttribute(hnd, wAttrs);
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
		std::cout << "\tPress Enter to Continue........";
		if (GetAsyncKeyState(VK_RETURN)) {
			return;
		}
		Sleep(150);
	}
}

int Application::retrieveMenuChoice(std::string title, std::string choices[], int size)
{
	int pointer = 0;
	while (true) {
		std::system("cls");
		SetConsoleTextAttribute(hnd, wAttrs);
		std::cout << title << std::endl;
		for (int i = 0; i != size; i++) {
			std::cout << "  ";
			if (i == pointer) {
				SetConsoleTextAttribute(hnd, wAttrs * 16);
			}
			std::cout << (i + 1) << ") " << choices[i] << std::endl;
			SetConsoleTextAttribute(hnd, wAttrs);
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
			Sleep(150);
		}
	}
}

void Application::saveInfoToFile(std::string *content)
{
	std::string filedir = getSaveFileInfo();
	FileUtils file;
	file.writeToFile(filedir, content);
	std::cout << "Voila! The file has been saved.";
	std::system("pause>nul");
}

// TODO : needs some refactoring
void Application::manageEncryption()
{
	int encryptionChoice = getEncryptionChoice();
	std::cout << std::endl;
	std::string *message = getInputInfo();
	CipherEncryption *cipher = getSuitableCipher(encryptionChoice);
	std::string *encrypted = cipher->encrypt(*message);
	delete message;
	std::cout << std::endl;
	char seeEncrypted = 0;
	std::cout << "Do you want to see encrypted message (Y/n) ? ";
	std::cin >> seeEncrypted;
	if (tolower(seeEncrypted) == 'y')
	{
		std::cout << std::endl;
		std::cout << "The information has been encrypted to the following : " << std::endl;
		std::cout << encrypted->c_str() << std::endl;
	}
	std::cout << std::endl;
	char saveEncrypted = 0;
	std::cout << "Do you want to save encrypted message (Y/n) ? ";
	std::cin >> saveEncrypted;
	if (tolower(saveEncrypted) ==  'y')
	{
		std::cout << std::endl;
		saveInfoToFile(encrypted);
	}
	delete encrypted;
	delete cipher;
}

// TODO : needs some refactoring
void Application::manageDecryption()
{
	std::string *message = getInputInfo();
	std::string key = message->substr(message->size() - 3, 3);
	int type = 0;
	if (key.find('x') != 1 || key[0] != key[2])
	{
		std::cout << std::endl << "There is no suitable cipher available for decryption.";
		std::system("pause>nul");
		return;
	}
	else
	{
		type = key[0] - '0';
	}
	*message = message->substr(0, message->size() - 3);
	CipherEncryption *cipher = getSuitableCipher(type);
	std::string *decrypted = cipher->decrypt(*message);
	delete message;
	char seeDecrypted = 0;
	std::cout << "Do you want to see decrypted message (Y/n) ? ";
	std::cin >> seeDecrypted;
	if (tolower(seeDecrypted) ==  'y')
	{
		std::cout << std::endl;
		std::cout << "The given information has been decrypted to the following : ";
		std::cout << std::endl;
		std::cout << decrypted->c_str() << std::endl;
	}
	std::cout << std::endl;;
	char saveDecrypted = 0;
	std::cout << "Do you want to save decrypted message (Y/n) ?";
	std::cin >> saveDecrypted;
	if (tolower(saveDecrypted) == 'y')
	{
		std::cout << std::endl;
		saveInfoToFile(decrypted);
	}
	delete decrypted;
	delete message;
}

/* Currently disabled for better working
void Application::showEndCredits()
{
	std::system("cls");
	std::string title = "Project done by the following students of XII - A :";
	std::string decoration(title.size(), '-');
	printHeading(title, decoration);
	printLines(3);
	printcnt("Abhishek Sriram, Roll No : 2");
	printcnt("Ashwin Kumar M, Roll No : 3");
	printcnt("Prajeen R G, Roll No : 20");
	printcnt("Vishal B, Roll No : 40");
	printLines(3);
}*/

void Application::runApp()
{
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
	// showEndCredits();
	std::system("pause>nul");
}