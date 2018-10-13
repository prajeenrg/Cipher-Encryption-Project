#include "Application.h"

char Application::getEncryptionChoice()
{
	char choice = 0;
	print("Which cipher do you want now ? ");
	std::cin >> choice;
	if (isWithInTheRange(choice, '1', '7'))
	{
		return choice;
	}
	return 0;
}

char Application::getMainMenuChoice()
{
	char choice = 0;
	print("What are you about to do ? ");
	std::cin >> choice;
	if (isWithInTheRange(choice, '1', '3'))
	{
		return choice;
	}
	return 0;
}

char Application::getInputChoice()
{
	char choice = 0;
	print("How can I get the input ? ");
	std::cin >> choice;
	if (isWithInTheRange(choice, '1', '2'))
	{
		return choice;
	}
	return 0;
}

std::string *Application::getInputInfo()
{
	showInputOptions();
	int inputForm = getInputChoice();
	std::string *input;
	while (inputForm == 0)
	{
		printNextLine();
		println("Try to give input from the available options.");
		printNextLine();
		showInputOptions();
		inputForm = getInputChoice();
	}
	if (inputForm == 1)
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

void Application::showEncryptionOptions()
{
	println("Types of ciphers available : ");
	println("1 -> Bitwise");
	println("2 -> Block");
	println("3 -> Caesar");
	println("4 -> Stream");
	println("5 -> Transpose");
	println("6 -> Vigenere");
	println("7 -> Xor (Exclusive OR)");
}

void Application::showMainMenu()
{
	println("What to do now ?");
	println("1 -> Encryption");
	println("2 -> Decryption");
	println("3 -> Exit");
}

void Application::showInputOptions()
{
	println("How are you going to enter the information ?");
	println("1 -> Type it now");
	println("2 -> Retrieve it from a existing file");
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
	showEncryptionOptions();
	int encryptionChoice = getEncryptionChoice();
	while (encryptionChoice == 0)
	{
		printNextLine();
		println("Try to choose an available cipher option.");
		printNextLine();
		showEncryptionOptions();
		encryptionChoice = getEncryptionChoice();
	}
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
	if (key.find('x') != 1 && !areTheSame(key[0], key[2]))
	{
		return;
	}
	else
	{
		type = key[0] - '0' + 1;
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
	char menuChoice = 0;
	do
	{
		clearScreen();
		showMainMenu();
		menuChoice = getMainMenuChoice();
		while (menuChoice == 0)
		{
			printNextLine();
			println("Try to follow the given instructions.");
			printNextLine();
			showMainMenu();
			menuChoice = getMainMenuChoice();
		}
		printNextLine();
		switch (menuChoice)
		{
		case '1':
			manageEncryption();
			break;
		case '2':
			manageDecryption();
			break;
		default:
			break;
		}
	} while (menuChoice != '3');
	clearScreen();
	showEndCredits();
	std::cin.get();
}