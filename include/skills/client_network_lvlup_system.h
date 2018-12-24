//
// Created by antonymo on 24.12.18.
//

#ifndef A_C_I_D_CLIENT_NETWORK_LVLUP_SYSTEM_H
#define A_C_I_D_CLIENT_NETWORK_LVLUP_SYSTEM_H


#include <network/network_manager.h>
#include <framework/reactive_system.h>
#include <network/network_id.h>
#include "LvlupSyncNode.h"

class ClientNetworkLvlupSystem : public ReactiveSystem<LvlupSyncNode> {
public:
    explicit ClientNetworkLvlupSystem(NetworkManager* _net) : net(_net) { }
    void execute() override {
        for (const auto &node : reactive_nodes) {
            uint16_t net_id = node->get_component<NameComponent>()->get_network_id();
           // std::cout << "let's sync mana " << net_id << std::endl;

            auto input_comp = node->get_component<SkillComponent>();
            if (input_comp) {
                sf::Packet packet_to_send;
                packet_to_send << input_comp->get_skill_updated();
                net->append(packet_to_send, LVLUP_SYSTEM);
            }
        }
    }

private:
    NetworkManager* net;
};

#endif //A_C_I_D_CLIENT_NETWORK_LVLUP_SYSTEM_H
