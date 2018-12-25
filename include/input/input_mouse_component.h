#ifndef ACID_INCLUDE_INPUT_MOUSE_COMPONENT_H_
#define ACID_INCLUDE_INPUT_MOUSE_COMPONENT_H_


#include <Box2D/Common/b2Math.h>

#include <i_component.h>

class InputMouseComponent : public IComponent {
  public:
    InputMouseComponent() = default;

    void set_mouse_pos(b2Vec2 pos) {
        mouse_pos = pos;
        update();
    }
    b2Vec2 get_mouse_pos() {
        return mouse_pos;
    }

  private:
    b2Vec2 mouse_pos;
};

#endif  // ACID_INCLUDE_INPUT_MOUSE_COMPONENT_H_
