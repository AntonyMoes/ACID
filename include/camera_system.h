#ifndef ACID_INCLUDE_CAMERA_SYSTEM_H_
#define ACID_INCLUDE_CAMERA_SYSTEM_H_


#include <graphical_subsystem.h>
#include <active_system.h>
#include <graphical_node.h>


class CameraSystem: public ActiveSystem<GraphicalNode> {
  public:
    void execute() const override {
        for (const auto& node: active_nodes) {
            // TODO(Xenobyte): customize this too
        }
    }

    std::vector<Entity*>& get_scope() {
        return visible_entity;
    }

  private:
    std::vector<Entity*> visible_entity;
    GraphSubsystem* subsystem;
};


#endif  // ACID_INCLUDE_CAMERA_SYSTEM_H_
