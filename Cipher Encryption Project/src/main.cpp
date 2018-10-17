#include "Application.h"

int main()
{
    Application *app = new Application();
    app->runApp();
    delete app;
    return 0;
}
