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


class NetworkSpawnSystem : public ActiveSystem<None>, public EntityLifeSystem {
  public:
    explicit NetworkSpawnSystem(NetworkManager* _net): net(_net) { }
    void execute() {
        auto& packet = net->get_system_packet(SPAWN_SYSTEM);
        while (!packet.endOfPacket()) {
            uint16_t id;
            float x;
            float y;
            bool is_current;
            packet >> id >> x >> y >> is_current;
            if (is_current) {
                auto main_player = new MainPlayer(id, sf::Vector2f(x, y));
                create_entity(main_player);
            } else {
                auto player = new ClientPlayer(id, sf::Vector2f(x, y));
                create_entity(player);
            }
        }
    }

  private:
    NetworkManager* net;
};

#endif //A_C_I_D_CLIENT_NETWORK_SPAWN_SYSTEM_H
