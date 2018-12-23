#include <graphic/texture_manager.h>
#include <iostream>

TextureManager::TextureManager() {
    std::ifstream infile("../textures/textures.txt");
    std::string line;
    uint16_t count = 0;
    while(getline(infile, line)) {
        auto* tex = new sf::Texture;
        tex->loadFromFile(line, sf::IntRect(0, 0, 32, 32));
        textures.insert(std::pair<uint16_t , sf::Texture*>(count++, tex));
    }

    infile.close();

    infile.open("../textures/hearts.txt");
    count = 0;
    while(getline(infile, line)) {
        auto* tex = new sf::Texture;
        tex->loadFromFile(line);
        hearts.insert(std::pair<uint16_t , sf::Texture*>(count++, tex));
    }

    infile.close();


}

const sf::Texture* TextureManager::getTexture(uint16_t id) {
    return textures[id];
}

const sf::Texture* TextureManager::getHP(int hp, int max_hp) {
    if (hp <= 0) return hearts[0];
    float percent = static_cast<float>(hp) / static_cast<float>(max_hp) * 100.0f;
    auto ratio = static_cast<uint16_t>(100.0f / hearts.size()) + 1;
    auto idx = static_cast<uint16_t>(percent / ratio);
    return hearts[idx];
}