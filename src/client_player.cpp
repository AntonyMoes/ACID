#include <client_player.h>

ClientPlayer::ClientPlayer(size_t id, sf::Vector2f pos): Entity(id) {
    auto pos_comp = new PositionComponent(pos);
    add_component(pos_comp);

    sf::Texture texture;
    if (!texture.loadFromFile("../textures/clientplayer.jpg",
                              sf::IntRect(0, 0, sizes.x, sizes.y))) {
        throw std::bad_typeid();
    }

    auto sprite = new sf::Sprite;
    sprite->setTexture(texture);
    auto text_pos = new TextureComponent(sprite);
    add_component(text_pos);
}