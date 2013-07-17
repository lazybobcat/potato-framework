#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H

// Forward declarations
namespace sf
{
    class Texture;
    class Font;
    class Shader;
}

template <typename Resource, typename Identifier>
class ResourceHolder;



// Textures
namespace Textures
{
    enum ID
    {

    };
}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;


// Fonts
namespace Fonts
{
    enum ID
    {
        Main,
        Monstruosor
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



#endif // RESOURCE_IDENTIFIERS_H
