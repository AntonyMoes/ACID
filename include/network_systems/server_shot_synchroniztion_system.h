//
// Created by vladimir on 07.12.18.
//

#ifndef A_C_I_D_SERVER_SHOT_SYNCHRONIZTION_SYSTEM_H
#define A_C_I_D_SERVER_SHOT_SYNCHRONIZTION_SYSTEM_H

#include <framework/reactive_system.h>
#include <fireball_creation_node.h>
#include <network_id.h>
#include <server_network_manager.h>
class ServerShotSynchronizationSystem: public ReactiveSystem<FireballCreationNode> {
  public:
    explicit ServerShotSynchronizationSystem(ServerNetworkManager* _net): net(_net) {

    }
    void execute() final {

    }
    void on_node_create(FireballCreationNode* node) final {
        auto collision_component = node->get_component<CollisionComponent>();
        auto id = (uint16_t)collision_component->get_parent_id();
        auto& pos = collision_component->get_body()->GetPosition();
        auto& speed = collision_component->get_body()->GetLinearVelocity();
        sf::Packet packet;
        packet << id << pos.x << pos.y << speed.x << speed.y;
        //TODO: send in scope only
        net->append_all(packet, FIRE_SYSTEM_ID);
    }

  private:
    ServerNetworkManager* net;
};
#endif //A_C_I_D_SERVER_SHOT_SYNCHRONIZTION_SYSTEM_H
