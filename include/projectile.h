#ifndef ACID_INCLUDE_PROJECTILE_H_
#define ACID_INCLUDE_PROJECTILE_H_

#include <Box2D/Box2D.h>

#include <entity.h>
#include <collision_component.h>
#include <damage_component.h>
#include <texture_component.h>
#include <body_component.h>
#include <death_component.h>
#include <lifetime_component.h>
#include <ACID_math.h>


class Projectile: public Entity {
  public:
    explicit Projectile(b2Vec2 pos, b2Vec2 direction);

  private:
    float speed = 10.0f;
    b2Vec2 sizes = {8.0f, 8.0f};
    int dmg = 10;
};

class ServerProjectile: public Entity {
public:
    explicit ServerProjectile(b2Vec2 pos, b2Vec2 direction);

private:
    float speed = 300.0f;
    b2Vec2 sizes = {8.0f, 8.0f};
    int dmg = 10;
};
#endif  // ACID_INCLUDE_FIREBALL_H_
