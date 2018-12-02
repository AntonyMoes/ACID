#include <main_player.h>

MainPlayer::MainPlayer(size_t id, sf::Vector2f pos): Entity(id) {
    sf::Texture texture;
    if (!texture.loadFromFile("../textures/mainplayer.jpg",
                              sf::IntRect(0, 0, sizes.x, sizes.y))) {
        throw std::bad_typeid();
    }

    auto sprite = new sf::Sprite;
    sprite->setTexture(texture);
    auto texture_comp = new TextureComponent(sprite);
    add_component(texture_comp);

    auto position_comp = new PositionComponent(pos);
    add_component(position_comp);

    auto camera_comp = new CameraComponent();
    add_component(camera_comp);

    auto input_move_comp = new InputMoveComponent();
    add_component(input_move_comp);

    auto input_mouse_comp = new InputMouseComponent();
    add_component(input_mouse_comp);
}