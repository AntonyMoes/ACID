#ifndef ACID_INCLUDE_EXP_BALL_H_
#define ACID_INCLUDE_EXP_BALL_H_


#include <Box2D/Box2D.h>

#include <single_world.h>
#include <entity.h>
#include <name_component.h>
#include <collision_component.h>
#include <drop_exp_component.h>
#include <texture_component.h>
#include <body_component.h>
#include <death_component.h>

class ExpBall: public Entity {
  public:
    ExpBall(b2Vec2& pos, size_t exp);

  private:
    b2Vec2 sizes = {8.0f, 8.0f};
};

#endif   // ACID_INCLUDE_EXP_BALL_H_
