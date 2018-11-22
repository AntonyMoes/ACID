#ifndef ACID_INCLUDE_GRAPHIC_MANAGER_H_
#define ACID_INCLUDE_GRAPHIC_MANAGER_H_


#include <SFML/Graphics.hpp>
#include <map>


class GraphicManager {
    GraphicManager();
    ~GraphicManager() = default;

    sf::Texture* get_texture(size_t id) {
        auto it = texture_map.find(id);
        if (it != texture_map.end()) {
            return &(it->second);
        }
        return nullptr;
    }

  private:
    std::map<size_t, sf::Texture> texture_map;
};


#endif  // ACID_INCLUDE_GRAPHIC_MANAGER_H_
