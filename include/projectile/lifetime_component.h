#ifndef ACID_INCLUDE_LIFETIME_COMPONENT_H_
#define ACID_INCLUDE_LIFETIME_COMPONENT_H_


#include <Box2D/Box2D.h>

#include <ACID_math.h>
#include <i_component.h>

class LifetimeComponent: public IComponent {
  public:
    LifetimeComponent(b2Body* body, b2Vec2 pos, float max_range):
    start_pos(pos),
    max_range(max_range),
    body(body) {}

    bool is_alive() const {
        b2Vec2 temp_pos = body->GetPosition();
        temp_pos *= SCALE;
        float range = ACIDMath::get_module_b2Vec2(start_pos, temp_pos);
        if (range >= max_range) {
            return false;
        }
        return true;
    }

  private:
    b2Vec2 start_pos;
    float max_range;
    b2Body* body;
};

#endif  // A_C_I_D_LIFETIME_COMPONENT_H
