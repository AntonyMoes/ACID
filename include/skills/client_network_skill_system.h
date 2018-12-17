#ifndef ACID_INCLUDE_CLIENT_NETWORK_SKILL_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_NETWORK_SKILL_SYSTEM_H_


#include <framework/reactive_system.h>
#include <network/network_manager.h>
#include <network/network_id.h>
#include "skill_sync_node.h"

class ClientNetworkSkillSystem : public ReactiveSystem<SkillSyncNode> {
  public:
    explicit ClientNetworkSkillSystem(NetworkManager* _net) : net(_net) { }
    void execute() override {
        for (const auto &node : reactive_nodes) {
            uint16_t net_id = node->get_component<NameComponent>()->get_network_id();
            std::cout << "let's sync mana " << net_id << std::endl;

            auto input_comp = node->get_component<InputSkillComponent>();
            if (input_comp) {
                // HARDCODE, BUT IT'S OK FOR NOW
                auto keys = input_comp->get_keys();

                sf::Packet packet_to_send;
                packet_to_send << keys->at(sf::Keyboard::F);
                net->append(packet_to_send, SKILL_SYSTEM);
            }
        }
    }

  private:
    NetworkManager* net;
};

#endif  // ACID_INCLUDE_CLIENT_NETWORK_SKILL_SYSTEM_H_
