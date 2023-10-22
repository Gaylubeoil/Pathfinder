#include "Application.hpp"
#include <iostream>

int main()
{
    try
    {
        Application app;
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }

    return 0;
}