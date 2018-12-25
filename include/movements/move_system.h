#ifndef ACID_INCLUDE_MOVE_SYSTEM_H_
#define ACID_INCLUDE_MOVE_SYSTEM_H_


#include <reactive_system.h>
#include <move_node.h>

class MoveSystem: public ActiveSystem<MoveNode> {
  public:
    void execute() override {
        for (auto& node : active_nodes) {
            auto input_move_comp = node->get_component<InputMoveComponent>();
            auto col_comp = node->get_component<CollisionComponent>();

            auto keys = input_move_comp->get_keys();
            auto body = col_comp->get_body();

            b2Vec2 speed{0, 0};

            if ((*keys)[sf::Keyboard::W]) {
                speed.y -= 200;
            }
            if ((*keys)[sf::Keyboard::A]) {
                speed.x -= 200;
            }
            if ((*keys)[sf::Keyboard::S]) {
                speed.y += 200;
            }
            if ((*keys)[sf::Keyboard::D]) {
                speed.x += 200;
            }
            speed.x = speed.x / SCALE;
            speed.y = speed.y / SCALE;

            body->SetLinearVelocity(speed);
        }
    }
};

#endif  // ACID_INCLUDE_MOVE_SYSTEM_H_
