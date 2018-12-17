//
// Created by sava on 12.12.18.
//

#ifndef ACID_TEXTURE_MANAGER_H
#define ACID_TEXTURE_MANAGER_H
#include <SFML/Graphics.hpp>
#include <map>
#include <fstream>
#include <string>
class TextureManager {
 public:
    TextureManager();
    const sf::Texture* getTexture(uint16_t);
    const sf::Texture* getHP(int, int);
 private:
    std::map<uint16_t , sf::Texture*> textures;
    std::map<uint16_t, sf::Texture*> hearts;
};

#endif //ACID_TEXTURE_MANAGER_H
