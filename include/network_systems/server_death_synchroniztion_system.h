#ifndef A_C_I_D_SERVER_DEATH_SYNCHRONIZTION_SYSTEM_H
#define A_C_I_D_SERVER_DEATH_SYNCHRONIZTION_SYSTEM_H

#include <reactive_system.h>
#include <entity_death_node.h>
#include <entity_life_system.h>
#include <single_world.h>
#include <server_network_manager.h>
#include <network_id.h>
class DeathSyncNode: public Node<DeathSyncNode> {
public:
    DeathSyncNode() {
        add_component<DeathComponent>();
    }
};

class ServerDeathSyncSystem: public ReactiveSystem<DeathSyncNode> {
  public:
    ServerDeathSyncSystem(ServerNetworkManager* _net): net(_net) {

    }
    void execute() override {
        for (auto node : reactive_nodes) {

            if (node->get_component<DeathComponent>()->get_state()) {
                sf::Packet packet;
                packet << node->get_component<DeathComponent>()->get_parent_id();
                net->append_all(packet, DEATH_SYSTEM);
            }
        }
    }
  private:
    ServerNetworkManager* net;
};

#endif //A_C_I_D_SERVER_DEATH_SYNCHRONIZTION_SYSTEM_H
