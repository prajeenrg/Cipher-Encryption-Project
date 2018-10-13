#include "Utils.h"

void print(const char *content)
{
    std::cout << content;
}

void print(const std::string *content)
{
    std::cout << *content;
}

void println(const char *content)
{
    std::cout << content << std::endl;
}

void println(const std::string *content)
{
    std::cout << *content << std::endl;
}

void printcnt(const char *content)
{
    int length = strlen(content);
    int position = static_cast<int>((SCREEN_WIDTH - length) / 2);
    std::cout << std::string(position - 1, ' ');
    println(content);
}

void printcnt(const std::string *content)
{
    int length = content->size();
    int position = static_cast<int>((SCREEN_WIDTH - length) / 2);
    std::cout << std::string(position - 1, ' ');
    println(content);
}

bool areTheSame(int a, int b)
{
    return a == b;
}

bool areTheSame(char a, char b)
{
    return a == b;
}

bool isWithInTheRange(char value, char lowerLimit, char upperLimit)
{
    return value >= lowerLimit && value <= upperLimit;
}

void clearScreen()
{
    int state = std::system("cls||clear");
    while (state == -1) {
        state = std::system("cls||clear");
    }
}

void printHeading(std::string &title, std::string &decoration)
{
    printcnt(&decoration);
    printcnt(&title);
    printcnt(&decoration);
}

void printNextLine()
{
    std::cout << std::endl;
}

void printLines(int noOfLines)
{
    for (int i = 0; i < noOfLines; i++)
    {
        printNextLine();
    }
}