#ifndef ACID_INCLUDE_CAMERA_COMPONENT_H_
#define ACID_INCLUDE_CAMERA_COMPONENT_H_

#include <i_component.h>


class CameraComponent: public IComponent {
  private:
    bool is_active;
};


#endif  // ACID_INCLUDE_CAMERA_COMPONENT_H_
