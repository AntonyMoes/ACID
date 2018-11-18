#ifndef ACID_INCLUDE_CAMERA_SYSTEM_H_
#define ACID_INCLUDE_CAMERA_SYSTEM_H_

#include <algorithm>

#include <active_system.h>
#include <graphic_node.h>
#include <entity.h>


class CameraSystem: public ActiveSystem<GraphicalNode> {
  public:
    void execute() const override {
        for (const auto& node: active_nodes) {
            // TODO(Xenobyte): customize this too
        }
    }

    std::vector<GraphicalNode*>& get_scope() {
        return visible_entity;
    }

  private:
    std::vector<GraphicalNode*> visible_entity;
    std::vector<GraphicalNode*> x_sorted;
    std::vector<GraphicalNode*> y_sorted;
};


#endif  // ACID_INCLUDE_CAMERA_SYSTEM_H_
