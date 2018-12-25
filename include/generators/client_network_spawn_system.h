#ifndef ACID_INCLUDE_CLIENT_NETWORK_SPAWN_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_NETWORK_SPAWN_SYSTEM_H_


#include <iostream>

#include <i_component.h>
#include <entity_life_system.h>
#include <network_manager.h>
#include <active_system.h>
#include <network_id.h>
#include <main_player.h>
#include <client_player.h>
#include <client_pos_sync_node.h>

class NetworkSpawnSystem : public ActiveSystem<ClientPosSyncNode>, public EntityLifeSystem {
  public:
    explicit NetworkSpawnSystem(NetworkManager* _net): net(_net) { }
    void execute() {
        auto& spawn_packet = net->get_system_packet(SPAWN_SYSTEM);
        while (!spawn_packet.endOfPacket()) {
            uint16_t id;
            float x = 0.0f;
            float y = 0.0f;
            int texture = 0;
            bool is_current = false;
            spawn_packet >> id >> x >> y >> is_current >> texture;
            if (is_current) {
                auto main_player = new MainPlayer(id, sf::Vector2f(x, y));
                create_entity(main_player);
            } else {
                auto player = new ClientPlayer(id, sf::Vector2f(x, y), texture);
                create_entity(player);
            }
        }
        auto& unspawn_packet = net->get_system_packet(UNSPAWN_SYSTEM);
        while (!unspawn_packet.endOfPacket()) {
            uint16_t id = 0;
            unspawn_packet >> id;
            for (auto node : active_nodes) {
                if (node->get_component<NameComponent>()->get_network_id() == id) {
                    delete_entity(node->get_component<NameComponent>()->get_parent_id());
                }
            }
        }
    }

  private:
    NetworkManager* net;
};

#endif  // ACID_INCLUDE_CLIENT_NETWORK_SPAWN_SYSTEM_H_
