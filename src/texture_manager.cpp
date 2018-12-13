//
// Created by sava on 12.12.18.
//

#include <texture_manager.hpp>
TextureManager::TextureManager() {
    std::ifstream infile("../textures/textures.txt");
    std::string line;
    uint16_t count = 0;
    while(getline(infile, line)) {
        auto* tex = new sf::Texture;
        tex->loadFromFile(line);
        textures.insert(std::pair<uint16_t , sf::Texture*>(count++, tex));
    }

    infile.close();
}

const sf::Texture* TextureManager::getTexture(const uint16_t id) {
    return textures[id];
}