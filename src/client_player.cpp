#include <client_player.h>

ClientPlayer::ClientPlayer(uint16_t id, float x, float y): Entity(id) {
    //Box 2D
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(0.0f, 0.0f);
    b2Body* body = SingleWorld::get_instance()->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(sizes.x / 2, sizes.y / 2);
    body->CreateFixture(&shape, 1.0f);
    auto player_collision_component = new CollisionComponent(body);
    body->SetUserData(player_collision_component);
    sf::Texture texture;

    TextureManager tm;
    texture = *tm.getTexture(0);
    auto sprite = new sf::Sprite;
    sprite->setOrigin(sizes.x / 2, sizes.y / 2);
    sprite->setTexture(*tm.getTexture(0));
    auto text_pos = new TextureComponent(sprite);
    auto* name_component = new NameComponent(true);
    name_component->set_network_id(id);
    auto death_component = new DeathComponent;
    auto health_component = new HealthComponent(100, 100);
    auto exp_component = new ExpComponent(20, 10, 2.0f, 2.0f);

    add_component(death_component);
    add_component(text_pos);
    add_component(player_collision_component);
    add_component(name_component);
    add_component(health_component);
    add_component(exp_component);
}

RemotePlayer::RemotePlayer(uint16_t id, float x, float y): Entity(id) {

}