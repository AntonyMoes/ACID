#include <exp_ball.h>

ExpBall::ExpBall(b2Vec2& pos, size_t exp) {
    b2BodyDef body_def;

    body_def.type = b2_kinematicBody;
    body_def.fixedRotation = true;
    body_def.position.Set(pos.x / SCALE, pos.y / SCALE);

    auto world = SingleWorld::get_instance();
    b2Body* body = world->CreateBody(&body_def);

    b2PolygonShape shape;
    shape.SetAsBox(sizes.x / 2 / SCALE, sizes.y / 2 / SCALE);
    body->CreateFixture(&shape, 1.0f);

    sf::Texture texture;
    if (!texture.loadFromFile("../textures/fireball.jpg",
                              sf::IntRect(0, 0, sizes.x, sizes.y))) {
        throw std::bad_typeid();
    }

    auto sprite = new sf::Sprite;
    sprite->setTexture(texture);
    sprite->setOrigin(sizes.x / 2, sizes.y / 2);
    sprite->setColor(sf::Color(0, 255, 0));

    auto collision_component = new CollisionComponent(body);
    body->SetUserData(collision_component);
    auto exp_component = new DropExpComponent(exp);
    auto texture_component = new TextureComponent(sprite);
    auto body_component = new BodyComponent(body);
    auto death_component = new DeathComponent;

    add_component(collision_component);
    add_component(exp_component);
    add_component(texture_component);
    add_component(body_component);
    add_component(death_component);
}