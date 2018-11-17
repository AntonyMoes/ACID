#ifndef ACID_INCLUDE_DRAW_SYSTEM_H_
#define ACID_INCLUDE_DRAW_SYSTEM_H_


#include <active_system.h>
#include <graphical_subsystem.h>
#include <graphical_node.h>
#include <entity.h>

class DrawSystem: public ActiveSystem<GraphicalNode> {
  public:
    DrawSystem() = default;
    ~DrawSystem() = default;

    void execute() const override {
        drawable_objects = subsystem->get_scope();

        for (const auto& obj: drawable_objects) {
            // Тут типа рисуеццо
            // TODO: подумоть над тем, что нужны только Sprite и Vector2f с коордами
        }
    }

  private:
    std::vector<sf::Sprite*> drawable_objects;
    GraphSubsystem* subsystem;
};


#endif  // ACID_INCLUDE_DRAW_SYSTEM_H_
