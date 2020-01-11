#include <projectile.h>
Projectile::Projectile(b2Vec2 pos, b2Vec2 direction): Entity() {
    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    body_def.fixedRotation = true;
    body_def.position.Set(pos.x / SCALE, pos.y / SCALE);
    auto world = SingleWorld::get_instance();
    b2Body* body = world->CreateBody(&body_def);

    b2PolygonShape shape;
    shape.SetAsBox(sizes.x / 2 / SCALE, sizes.y / 2 / SCALE);

    body->CreateFixture(&shape, 1.0f);
    ACIDMath::get_unit_b2Vec2(direction);
    b2Vec2 velocity(direction.x * speed / SCALE, direction.y * speed / SCALE);
    body->SetLinearVelocity(velocity);

    auto collision_comp = new CollisionComponent(body);
    body->SetUserData(collision_comp);
    add_component(collision_comp);

    auto body_comp = new BodyComponent(body);
    add_component(body_comp);

    auto damage_comp = new DamageComponent(dmg);
    add_component(damage_comp);

    auto texture = new sf::Texture;
    if(!texture->loadFromFile("../textures/fireball.png")) {std::cout << "FUCK\n";}
    auto sprite = new sf::Sprite;
    sprite->setScale(2.0f, 2.0f);
    sprite->setTexture(*texture);
    sprite->setOrigin(sizes.x / 2, sizes.y / 2);
    float angle = ACIDMath::get_angle_from_b2Vec(direction);
    angle += 180; // <-- maybe sprite is placed memely, cause angle is calcd correctly
    sprite->setRotation(angle);

    auto texture_comp = new TextureComponent(sprite);
    add_component(texture_comp);

    auto lifetime_comp = new LifetimeComponent(body, pos, 400);
    add_component(lifetime_comp);

    auto death_comp = new DeathComponent;
    add_component(death_comp);
}


ServerProjectile::ServerProjectile(b2Vec2 pos, b2Vec2 direction): Entity() {
    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    body_def.fixedRotation = true;
    body_def.position.Set(pos.x / SCALE, pos.y / SCALE);

    auto world = SingleWorld::get_instance();
    b2Body* body = world->CreateBody(&body_def);

    b2PolygonShape shape;
    shape.SetAsBox(sizes.x / 2 / SCALE, sizes.y / 2 / SCALE);

    body->CreateFixture(&shape, 1.0f);
    ACIDMath::get_unit_b2Vec2(direction);
    b2Vec2 velocity(direction.x * speed / SCALE, direction.y * speed / SCALE);
    body->SetLinearVelocity(velocity);

    auto collision_comp = new CollisionComponent(body);
    body->SetUserData(collision_comp);
    add_component(collision_comp);

    auto body_comp = new BodyComponent(body);
    add_component(body_comp);

    auto damage_comp = new DamageComponent(dmg);
    add_component(damage_comp);

    auto lifetime_comp = new LifetimeComponent(body, pos, 400);
    add_component(lifetime_comp);

    auto death_comp = new DeathComponent;
    add_component(death_comp);
}