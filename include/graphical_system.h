#ifndef ACID_INCLUDE_DRAW_SYSTEM_H_
#define ACID_INCLUDE_DRAW_SYSTEM_H_


#include <active_system.h>
#include <camera_system.h>
#include <graphic_node.h>
#include <entity.h>

class GraphicalSystem: public ActiveSystem<CameraNode> {
  public:
    GraphicalSystem() = default;
    ~GraphicalSystem() = default;

    void execute() const override {
        drawable_objects = camera->get_scope();

        for (const auto& obj: drawable_objects) {
            // Тут типа рисуеццо
            // TODO: подумоть над тем, что нужны только Sprite и Vector2f с коордами
        }
    }

  private:
    std::vector<sf::Sprite*> drawable_objects;
    CameraSystem* camera;
};


#endif  // ACID_INCLUDE_DRAW_SYSTEM_H_
