//
// Created by antonymo on 17.12.18.
//

#ifndef ACID_INCLUDE_SERVER_NETWORK_MANA_SYSTEM_H_
#define ACID_INCLUDE_SERVER_NETWORK_MANA_SYSTEM_H_


#include <network/server_network_manager.h>
#include <framework/reactive_system.h>
#include <network/network_id.h>
#include "mana_sync_node.h"

class ServerNetworkManaSystem: public ReactiveSystem<ManaSyncNode> {
public:
    explicit ServerNetworkManaSystem(ServerNetworkManager* _net) : net(_net) { }
    void execute() final {
        for (const auto &node : reactive_nodes) {
            uint16_t net_id = node->get_component<NameComponent>()->get_network_id();
            std::cout << "let's sync mana " << net_id << std::endl;

            auto mana_comp = node->get_component<ManaComponent>();
            if (mana_comp) {
                auto id = mana_comp->get_parent_id();
                auto mana = mana_comp->get_mana();
                auto max_mana = mana_comp->get_max_mana();
                auto regen_rate = mana_comp->get_regen_rate();

                sf::Packet packet_to_send;
                packet_to_send << net_id << mana << max_mana << regen_rate;
                net->append(net_id, packet_to_send, MANA_SYSTEM);
            }
        }
    }

private:
    ServerNetworkManager* const net;
};

#endif  // ACID_INCLUDE_SERVER_NETWORK_MANA_SYSTEM_H_
