#include <projectile.h>

Projectile::Projectile(b2Vec2 pos, b2Vec2 direction): Entity() {
    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    body_def.fixedRotation = true;
    body_def.position.Set(pos.x, pos.y);

    auto world = SingleWorld::get_instance();
    b2Body* body = world->CreateBody(&body_def);

    b2PolygonShape shape;
    shape.SetAsBox(sizes.x / 2, sizes.y / 2);

    body->CreateFixture(&shape, 1.0f);
    ACIDMath::get_unit_b2Vec2(direction);
    b2Vec2 velocity(direction.x * speed, direction.y * speed);
    body->SetLinearVelocity(velocity);

    auto collision_comp = new CollisionComponent(body);
    add_component(collision_comp);

    auto damage_comp = new DamageComponent(dmg);
    add_component(damage_comp);

    sf::Texture texture;
    if (!texture.loadFromFile("../textures/fireball.jpg",
                              sf::IntRect(0, 0, sizes.x, sizes.y))) {
        throw std::bad_typeid();
    }
    auto sprite = new sf::Sprite;
    sprite->setTexture(texture);
    float angle = ACIDMath::get_angle_from_b2Vec(direction);
    sprite->setRotation(angle);

    auto texture_comp = new TextureComponent(sprite);
    add_component(texture_comp);
}