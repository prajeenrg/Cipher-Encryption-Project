#include <iostream>

#include "Application.h"

int main()
{
    std::system("COLOR 0A || clear"); // This colorize screen in windows but not for linux
    Application *app = new Application();
    app->runApp();
    delete app;
    return std::cin.get();
}
