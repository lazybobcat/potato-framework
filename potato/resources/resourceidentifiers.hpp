#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H

// Forward declarations
namespace sf
{
    class Texture;
    class Font;
    class Shader;
    class Music;
    class SoundBuffer;
}

template <typename Resource, typename Identifier>
class ResourceHolder;



// Textures
namespace Textures
{
    enum ID
    {
        Particle
    };
}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;


// Fonts
namespace Fonts
{
    enum ID
    {
        Main
    };
}

typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;


// Shaders
namespace Shaders
{
    enum ID
    {

    };
}
typedef ResourceHolder<sf::Shader, Shaders::ID> ShaderHolder;


// Musics
namespace Musics
{
    enum ID
    {

    };
}


// Sounds
namespace Sounds
{
    enum ID
    {

    };
}
typedef ResourceHolder<sf::SoundBuffer, Sounds::ID> SoundHolder;


// Scripts
namespace Scripts
{
    enum ID
    {
        HelloWorld
    };
}



#endif // RESOURCE_IDENTIFIERS_H
