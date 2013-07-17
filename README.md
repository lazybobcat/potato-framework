Potato
================

Potato is a framework and a base to do a video game in C++ with SFML.

It needs :
===

*   A good understanding of C++
*   A compiler that support C++11 (lambda, nullptr, shared ptr, threads)
*   SFML 2.0

It includes :
===

*   Window handling
*   Input and events (even game event) handling
*   States and State Stack
*   Entities and Scene Tree
*   Resources Handling

It will include :
===

*   Very Simple GUI (buttons and text zones)
*   Simple Particle system
*   LUA scripting language
*   Possibly Box2D interface
*   Visual Effect (interface for shaders)
*   Music and Sound handling

Usage
===

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

Once you've done that, I let you discoer the framework in details.

To add screens, inherit from the `State` class, add your `State::ID` into the `states/stateidentifiers.h` file. Then, register your state in `Application::registerStates()` method.

To add entities, inherit from `SceneNode` or `Entity`.

Then implement your whole gameplay.
