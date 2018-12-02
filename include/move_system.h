#ifndef ACID_INCLUDE_MOVE_SYSTEM_H_
#define ACID_INCLUDE_MOVE_SYSTEM_H_


#include <reactive_system.h>
#include <move_node.h>


class MoveSystem: public ReactiveSystem<MoveNode> {
  public:
    void execute() override {
        for (auto& node : reactive_nodes) {
            auto input_move_comp = node->get_component<InputMoveComponent>();
            auto col_comp = node->get_component<CollisionComponent>();

            auto keys = input_move_comp->get_keys();
            auto body = col_comp->get_body();
            if ((*keys)[sf::Keyboard::W]) {
                body->SetLinearVelocity(b2Vec2(0.0f, -2.0f));
            }
            if ((*keys)[sf::Keyboard::A]) {
                body->SetLinearVelocity(b2Vec2(-2.0f, 0.0f));
            }
            if ((*keys)[sf::Keyboard::S]) {
                body->SetLinearVelocity(b2Vec2(0.0f, 2.0f));
            }
            if ((*keys)[sf::Keyboard::D]) {
                body->SetLinearVelocity(b2Vec2(2.0f, 0.0f));
            }
        }
    }
};


#endif  // ACID_INCLUDE_MOVE_SYSTEM_H_
