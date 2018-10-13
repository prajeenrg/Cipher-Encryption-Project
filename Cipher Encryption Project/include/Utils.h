#pragma once
#define SCREEN_WIDTH 120
#include <cstring>
#include <string>
#include <iostream>

void print(const char *);
void print(const std::string *);

void println(const char *);
void println(const std::string *);

void printcnt(const char *);
void printcnt(const std::string *);

bool areTheSame(int, int);
bool areTheSame(char, char);

bool isWithInTheRange(char, char, char);

void clearScreen();

void printHeading(std::string &, std::string &);
void printNextLine();
void printLines(int);