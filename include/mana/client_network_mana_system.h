#ifndef ACID_INCLUDE_CLIENT_NETWORK_MANA_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_NETWORK_MANA_SYSTEM_H_


#include <framework/active_system.h>
#include <network/network_manager.h>
#include <network/network_id.h>
#include "mana_sync_node.h"

class ClientNetworkManaSystem : public ActiveSystem<ManaSyncNode> {
  public:
    explicit ClientNetworkManaSystem(NetworkManager* _net): net(_net) {
    }
    void execute() final{
        //TODO: implementation needed
        sf::Packet& received_packet = net->get_system_packet(MANA_SYSTEM);
        while (!received_packet.endOfPacket()) {
            uint16_t id = 0;
            uint16_t mana = 0;
            uint16_t max_mana = 0;
            uint16_t regen_rate = 0;

            received_packet >> id >> mana >> max_mana >> regen_rate;

            for (const auto &node : active_nodes) {
                //if (node->get_component<NameComponent>()->get_network_id() == id) {
                    auto mana_comp = node->get_component<ManaComponent>();
                    if (mana_comp) {
                        mana_comp->set_mana(mana);
                        mana_comp->set_max_mana(max_mana);
                        mana_comp->set_regen_rate(regen_rate);
                    }
                //}
            }
        }
    }

private:
    NetworkManager* const net;
};

#endif  // ACID_INCLUDE_CLIENT_NETWORK_MANA_SYSTEM_H_
