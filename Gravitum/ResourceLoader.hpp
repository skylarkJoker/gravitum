#pragma once
#include <unordered_map>
#include <map>
#include <memory>
#include <assert.h>
#include "SFML/Graphics.hpp"



template <typename Resource, typename Identifier>
class ResourceLoader
{
public:
    Resource &get(Identifier);
    const Resource &get(Identifier) const;

    void load(Identifier, const std::string &);
    template <typename Parameter>
    void load(Identifier, const std::string &, const Parameter &);

private:
    std::unordered_map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceLoader.inl"

namespace Textures
{
    enum class ID
    {
        Background,
        Ground,
        Ice,
        Player,
        Player2,
        Sword
    };
}
typedef ResourceLoader<sf::Texture, Textures::ID> TextureLoader;