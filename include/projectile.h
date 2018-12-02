#ifndef ACID_INCLUDE_PROJECTILE_H_
#define ACID_INCLUDE_PROJECTILE_H_


#include <Box2D/Box2D.h>

#include <entity.h>
#include <collision_component.h>
#include <damage_component.h>
#include <texture_component.h>


class Projectile: public Entity {
  public:
    explicit Projectile(b2Vec2 direction, b2Vec2 pos);

  private:
    float speed = 300.0f;
    b2Vec2 sizes = {8.0f, 8.0f};
    int dmg = 10;
};

#endif  // ACID_INCLUDE_FIREBALL_H_
