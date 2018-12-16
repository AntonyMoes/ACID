#include <client_player.h>
#include <single_world.h>
#include <collision_component.h>
#include <camera_component.h>
#include <input_move_component.h>
#include <input_mouse_component.h>
#include <name_component.h>
#include <death_component.h>

ClientPlayer::ClientPlayer(uint16_t id, float x, float y): Entity(id) {
    //Box 2D
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(10.0f, 10.0f);
    b2Body* body = SingleWorld::get_instance()->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(16.0f, 16.0f);
    body->CreateFixture(&shape, 1.0f);
    auto player_collision_component = new CollisionComponent(body);
    body->SetUserData(player_collision_component);
    sf::Texture texture;

    // TODO Load from texture manager
    if (!texture.loadFromFile("../textures/clientplayer.jpg",
                              sf::IntRect(0, 0, sizes.x, sizes.y))) {
        throw std::bad_typeid();
    }

    auto sprite = new sf::Sprite;
    sprite->setOrigin(sizes.x / 2, sizes.y / 2);
    sprite->setTexture(texture);
    auto text_pos = new TextureComponent(sprite);
    auto* name_component = new NameComponent();
    name_component->set_network_id(id);
    auto death_component = new DeathComponent;
    add_component(death_component);
    add_component(text_pos);
    add_component(player_collision_component);
    add_component(name_component);
}

RemotePlayer::RemotePlayer(uint16_t id, float x, float y): Entity(id) {

}