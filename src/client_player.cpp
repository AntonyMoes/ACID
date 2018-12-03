#include <client_player.h>

ClientPlayer::ClientPlayer(uint16_t id, float x, float y): Entity(id) {
    auto pos_comp = new PositionComponent(sf::Vector2f(x, y));
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