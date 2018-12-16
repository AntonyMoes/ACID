#ifndef ACID_INCLUDE_BODY_COMPONENT_H_
#define ACID_INCLUDE_BODY_COMPONENT_H_

#include <Box2D/Box2D.h>

#include <i_component.h>

class BodyComponent: public IComponent {
  public:
    explicit BodyComponent(b2Body* body): body(body) {}

    b2Body* get_body() const {
        return body;
    }

  private:
    b2Body* body;
};

#endif  // ACID_INCLUDE_BODY_COMPONENT_H_
