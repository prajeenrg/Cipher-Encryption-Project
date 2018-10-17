#include "TransposeCipherEncryption.h"

std::string TransposeCipherEncryption::getEncryptionKey()
{
    return "4x4";
}

std::string *TransposeCipherEncryption::encrypt(std::string *message)
{
    std::string *output = new std::string;
    const int SIZE = message->size();
    char letter = 0;
    int blockSize = static_cast<int>(sqrt(SIZE)) + 1;
    for (int i = 0; i < blockSize; i++)
    {
        for (int j = 0; j < blockSize; j++)
        {
            int position = i + (j * blockSize);
            if (position > SIZE)
            {
                letter = 1;
            }
            else
            {
                letter = message->at(position);
            }
            output->push_back(letter);
        }
    }
    output->append(getEncryptionKey());
    return output;
}

std::string *TransposeCipherEncryption::decrypt(std::string *cipher)
{
    std::string *output = new std::string;
    const int SIZE = cipher->size();
    int blockSize = static_cast<int>(sqrt(SIZE));
    for (int i = 0; i < blockSize; i++)
    {
        for (int j = 0; j < blockSize; j++)
        {
            int position = i + j * blockSize;
            char letter = static_cast<char>(cipher->at(position));
            if (letter != 1)
            {
                output->push_back(letter);
            }
        }
    }
    return output;
}