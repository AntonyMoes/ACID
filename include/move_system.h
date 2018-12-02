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
                //body->SetLinearVelocity(b2Vec2(0.0f, -20.0f));
                speed.y -= 20;
            }
            if ((*keys)[sf::Keyboard::A]) {
                //body->SetLinearVelocity(b2Vec2(-20.0f, 0.0f));
                speed.x -= 20;
            }
            if ((*keys)[sf::Keyboard::S]) {
                //body->SetLinearVelocity(b2Vec2(0.0f, 20.0f));
                speed.y += 20;
            }
            if ((*keys)[sf::Keyboard::D]) {
                //body->SetLinearVelocity(b2Vec2(20.0f, 0.0f));
                speed.x += 20;
            }

            body->SetLinearVelocity(speed);


        }
    }
};


#endif  // ACID_INCLUDE_MOVE_SYSTEM_H_
