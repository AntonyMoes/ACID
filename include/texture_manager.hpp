//
// Created by sava on 12.12.18.
//

#ifndef ACID_TEXTURE_MANAGER_HPP
#define ACID_TEXTURE_MANAGER_HPP
#include <SFML/Graphics.hpp>
#include <map>
#include <fstream>
#include <string>
class TextureManager {
 public:
    TextureManager();
    const sf::Texture* getTexture(const uint16_t);
 private:
    std::map<uint16_t , sf::Texture*> textures;
};

#endif //ACID_TEXTURE_MANAGER_HPP
