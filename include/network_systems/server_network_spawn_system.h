#ifndef ACID_INCLUDE_SERVER_NETWORK_SPAWN_SYSTEM_H_
#define ACID_INCLUDE_SERVER_NETWORK_SPAWN_SYSTEM_H_

#include <entity_life_system.h>
#include <server_player.h>
#include <server_pos_sync_node.h>

#include <server_network_manager.h>

#include <unistd.h>
#include <active_system.h>
#include <network_id.h>

class NetworkSpawnSystem : public ActiveSystem<ServerPosSyncNode>, public EntityLifeSystem, private IClientObserver {
  public:
    explicit NetworkSpawnSystem(ServerNetworkManager* _net): net(_net) { net->register_observer(this); }
    void execute() {
        //usleep(40000);
    }

    void on_client_connect(uint16_t client) override {
        //TODO здесь надо рассылать данные о входе клиента и создании его сущности (net->append)
        static float pos = 0;
        std::cout << "connected" << std::endl;



        for (const auto& send_player : active_nodes) {
            std::cout << "we have NODES" << std::endl;
            sf::Packet spawn_packet;
            spawn_packet << client << pos << pos << false;
            net->append(send_player->get_component<NameComponent>()->get_network_id(), spawn_packet, SPAWN_SYSTEM);
        }


        auto player = new ServerPlayer(client, pos, pos);
        create_entity(player);

        sf::Packet client_spawn_packet;
        client_spawn_packet << client << pos << pos << true;
        pos += 50;

        net->append(client, client_spawn_packet, SPAWN_SYSTEM);



        for (const auto &node : active_nodes) {
            std::cout << "НА МЕСТЕ" << std::endl;

            sf::Packet old_players_packet;

            auto id = node->get_component<NameComponent>()->get_network_id();
            auto player_pos = node->get_component<CollisionComponent>()->get_body()->GetPosition();

            old_players_packet << id << float(player_pos.x) << float(player_pos.y) << false;

            net->append(client, old_players_packet, SPAWN_SYSTEM);
        }
    }

    void on_client_disconnect(uint16_t client) override {
        //TODO а здесь надо рассылать данные о выходе клиента и удалении его сущности (net->append)
        std::cout << "disconnected" << std::endl;
        auto disconnected = active_nodes.end();
        for (const auto &node : active_nodes) {
            if (node->get_component<NameComponent>()->get_network_id() == client) {
                delete_entity(node->get_component<NameComponent>()->get_parent_id());
                std::cout << "disconnected for sure" << std::endl;
                break;
            }
        }
    }

  private:
    ServerNetworkManager* net;
    std::map<uint16_t, Entity*> player_map;

};

#endif  // ACID_INCLUDE_SERVER_NETWORK_SPAWN_SYSTEM_H_
