#include <client_player.h>

ClientPlayer::ClientPlayer(uint16_t id, float x, float y, int texture_id): Entity(id) {
    //Box 2D
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x / SCALE, y / SCALE);
    b2Body* body = SingleWorld::get_instance()->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(sizes.x / 2 / SCALE, sizes.y / 2 / SCALE);
    body->CreateFixture(&shape, 1.0f);
    auto player_collision_component = new CollisionComponent(body);
    body->SetUserData(player_collision_component);
    TextureManager tm;
    std::cout << "texture " << texture_id <<  std::endl;

    auto sprite = new sf::Sprite;
    sprite->setOrigin(sizes.x / 2, sizes.y / 2);
    sprite->setTexture(*tm.getTexture(texture_id));
    auto text_pos = new TextureComponent(sprite);
    auto* name_component = new NameComponent(true);
    name_component->set_network_id(id);
    auto death_component = new DeathComponent;
    auto health_component = new HealthComponent(100, 100);

    add_component(death_component);
    add_component(text_pos);
    add_component(player_collision_component);
    add_component(name_component);
    add_component(health_component);
}

