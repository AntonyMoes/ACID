#ifndef ACID_INCLUDE_TEXTURE_MANAGER_H_
#define ACID_INCLUDE_TEXTURE_MANAGER_H_


#include <SFML/Graphics.hpp>
#include <map>
#include <fstream>
#include <string>

class TextureManager {
  public:
    TextureManager();
    const sf::Texture* getTexture(uint16_t);
    const sf::Texture* getHP(int, int);
    const sf::Texture* getMP(int, int);
    const sf::Texture* getEXP(int, int);

  private:
    std::map<uint16_t, sf::Texture*> textures;
    std::map<uint16_t, sf::Texture*> hearts;
    std::map<uint16_t, sf::Texture*> mana;
    std::map<uint16_t, sf::Texture*> exp;
};

#endif  // ACID_INCLUDE_TEXTURE_MANAGER_H_
