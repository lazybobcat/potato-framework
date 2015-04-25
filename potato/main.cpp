#include "application.hpp"
#include <iostream>

using namespace std;

int main()
{
    const unsigned int width = 1280, height = width * 9/16;
    try {
        Application game(width, height, "Potato Framework Application");
        game.run();
    } catch(std::exception& e) {
        std::cerr << "Game ended unexpectedely : " << std::endl;
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

