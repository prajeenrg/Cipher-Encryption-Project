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
		printNextLine();
		println("Please end your message with a backtick symbol (`) ");
		std::getline(std::cin, *input, '`');
	}
	else
	{
		printNextLine();
		std::cin.ignore();
		std::string fileloc = getFileInfo();
		FileUtils file;
		input = file.readFromFile(fileloc);
		while (input == nullptr)
		{
			printNextLine();
			println("The file requested is not accessible. Try again.");
			printNextLine();
			fileloc = getFileInfo();
			input = file.readFromFile(fileloc);
		}
	}
	return input;
}

std::string Application::getFileInfo()
{
	std::string filedir, filename;
	print("Where can I get the file ? ");
	std::getline(std::cin, filedir);
	print("What is the name of the file ? ");
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
	std::cin.ignore();
	print("Where should the file be stored ? ");
	std::getline(std::cin, filedir);
	print("What should be the name of the file ? ");
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

void Application::showEncryptedMessage(std::string *message)
{
	println("Here is your encrypted message : ");
	println(message);
}

void Application::showDecryptedCipher(std::string *message)
{
	println("Here is your decrypted cipher text : ");
	println(message);
}

void Application::saveInfoToFile(std::string *content)
{
	std::string filedir = getSaveFileInfo();
	FileUtils file;
	file.writeToFile(filedir, content);
	println("Voila! The file has been saved.");
	std::cin.get();
}

void Application::manageEncryption()
{
	int encryptionChoice = getEncryptionChoice();
	printNextLine();
	std::string *message = getInputInfo();
	CipherEncryption *cipher = getSuitableCipher(encryptionChoice);
	std::string *encrypted = cipher->encrypt(*message);
	printNextLine();
	char seeEncrypted = 0;
	print("Do you want to see encrypted message ? (Y/n) ");
	std::cin >> seeEncrypted;
	if (areTheSame(seeEncrypted, 'Y') || areTheSame(seeEncrypted, 'y'))
	{
		printNextLine();
		showEncryptedMessage(encrypted);
	}
	printNextLine();
	char saveEncrypted = 0;
	print("Do you want to save encrypted message ? (Y/n) ");
	std::cin >> saveEncrypted;
	if (areTheSame(saveEncrypted, 'Y') || areTheSame(saveEncrypted, 'y'))
	{
		printNextLine();
		saveInfoToFile(encrypted);
	}
	delete message;
	delete encrypted;
	delete cipher;
}

void Application::manageDecryption()
{
	std::string *message = getInputInfo();
	std::string key = message->substr(message->size() - 3, 3);
	int type = 0;
	if (key.find('x') != 1 || key[0] != key[2])
	{
		return;
	}
	else
	{
		type = key[0] - '0';
	}
	*message = message->substr(0, message->size() - 3);
	CipherEncryption *cipher = getSuitableCipher(type);
	std::string *decrypted = cipher->decrypt(*message);
	printNextLine();
	char seeDecrypted = 0;
	print("Do you want to see decrypted message ? (Y/n) ");
	std::cin >> seeDecrypted;
	if (areTheSame(seeDecrypted, 'Y') || areTheSame(seeDecrypted, 'y'))
	{
		showDecryptedCipher(decrypted);
	}
	printNextLine();
	char saveDecrypted = 0;
	print("Do you want to save decrypted message ? (Y/n) ");
	std::cin >> saveDecrypted;
	if (areTheSame(saveDecrypted, 'Y') || areTheSame(saveDecrypted, 'y'))
	{
		printNextLine();
		saveInfoToFile(decrypted);
	}
	delete cipher;
	delete decrypted;
	delete message;
}

void Application::showEndCredits()
{
	clearScreen();
	std::string title = "Project done by the following students of XII - A :";
	std::string decoration(title.size(), '-');
	printHeading(title, decoration);
	printLines(3);
	printcnt("Abhishek Sriram, Roll No : 2");
	printcnt("Ashwin Kumar M, Roll No : 3");
	printcnt("Prajeen R G, Roll No : 20");
	printcnt("Vishal B, Roll No : 40");
	printLines(3);
}

void Application::runApp()
{
	showMainScreen();
	do
	{
		clearScreen();
		int menuChoice = getMainMenuChoice();
		printNextLine();
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
	clearScreen();
	showEndCredits();
	std::cin.get();
}