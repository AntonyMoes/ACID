#include <main_player.h>
#include <typeinfo>
#include <input_mouse_component.h>
#include <name_component.h>
#include <single_world.h>
#include <collision_component.h>
#include <camera_component.h>
#include <input_move_component.h>
#include <texture_manager.h>
MainPlayer::MainPlayer(uint16_t id, float x, float y): Entity(id) {
    // Creating drawable object
    sf::Texture texture;

    // TODO Load from texture manager
    if (!texture.loadFromFile("../textures/clientplayer.jpg", sf::IntRect(0, 0, 32, 32))) {
        throw std::bad_typeid();
    }
    TextureManager tm;
    auto* player_sprite = new sf::Sprite;
    player_sprite->setTexture(*tm.getTexture(0));
    player_sprite->setOrigin(16.0f, 16.0f);

    //Box 2D
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;
    bodyDef.position.Set(10.0f, 10.0f);
    b2Body* body = SingleWorld::get_instance()->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(16.0f, 16.0f);
    body->CreateFixture(&shape, 1.0f);
    auto* player_collision_component= new CollisionComponent(body);

    // Creating graph components
    auto* player_texture_component = new TextureComponent(player_sprite);
    auto pos_comp = new PositionComponent(sf::Vector2f(x, y));
    auto* camera_component = new CameraComponent;
    auto* input_move_component = new InputMoveComponent;
    auto* input_mouse_component = new InputMouseComponent;
    auto* name_component = new NameComponent();
    name_component->set_network_id(id);

    add_component(player_texture_component);
    add_component(player_collision_component);
    add_component(camera_component);
    add_component(input_move_component);
    add_component(input_mouse_component);
    add_component(name_component);
    add_component(pos_comp);
}