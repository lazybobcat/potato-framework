Potato
================

Potato is a framework and a base to do a video game in C++ with SFML.

It's based on the book [SFML Game Development](http://www.packtpub.com/sfml-game-development/book) edited by Packt. I can only advise you to get your copy of the book, it's awesome ! You can checkout the book [GitHub repository](https://github.com/LaurentGomila/SFML-Game-Development-Book) as well.

Even if I change proposed code to fit my needs, I publish it with the same restrictions, meaning : You are free to use and modify the code as you wish, except for commercial use.

It needs :
==

*   A good understanding of C++
*   A compiler that support C++11 (lambda, nullptr, shared ptr, threads)
*   SFML 2.0
*   Lua 5.2 lib

It includes :
==

*   Window handling
*   Input and events (even game event) handling
*   States and State Stack
*   Entities and Scene Tree
*   Resources Handling
*   Very Simple GUI (buttons and text zones)
*   Music and Sound handling
*   LUA scripting language
*   (Very) Simple animations (spritesheets)
*   Simple Particle system
*   Simple QuadTree (non-object-number-adaptative)

It will include :
==

*   Visual Effect (interface for shaders)

Usage
==

You can open a simple window with the code "as-is". Simply create a main.cpp and do :

    int main()
    {
        try {
            unsigned int width = 1024, height = width * 3/4; // Ratio 4:3
            Application game(width, height, "Potato for life");
            game.run();
        } catch(std::exception& e) {
            std::cerr << std::endl << "Exception: " << e.what() << std::endl;
        }
        return 0;
    }

Once you've done that, I let you discover the framework in details.

To add screens, inherit from the `State` class, add your `State::ID` into the `states/stateidentifiers.h` file. Then, register your state in `Application::registerStates()` method.

To add entities, inherit from `SceneNode` or `Entity`.

Then implement your whole gameplay.
