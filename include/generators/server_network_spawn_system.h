#ifndef ACID_INCLUDE_SERVER_NETWORK_SPAWN_SYSTEM_H_
#define ACID_INCLUDE_SERVER_NETWORK_SPAWN_SYSTEM_H_


#include <unistd.h>

#include <entity_life_system.h>
#include <server_player.h>
#include <server_pos_sync_node.h>
#include <server_network_manager.h>
#include <active_system.h>
#include <network_id.h>

class NetworkSpawnSystem : public ActiveSystem<ServerPosSyncNode>, public EntityLifeSystem, private IClientObserver {
  public:
    explicit NetworkSpawnSystem(ServerNetworkManager* _net): net(_net) { net->register_observer(this); }
    void execute() {

    }

    void on_client_connect(uint16_t client) override {
        //TODO здесь надо рассылать данные о входе клиента и создании его сущности (net->append)
        static float pos = 0;
        for (const auto& send_player : active_nodes) {
            sf::Packet spawn_packet;
            spawn_packet << client << pos << pos << false;
            net->append(send_player->get_component<NameComponent>()->get_network_id(), spawn_packet, SPAWN_SYSTEM);
        }

        auto player = new ServerPlayer(client, pos, pos);
        player->get_component<NameComponent>()->set_network_id(client);
        create_entity(player);

        sf::Packet client_spawn_packet;
        client_spawn_packet << client << pos << pos << true;
        pos += 50;

        net->append(client, client_spawn_packet, SPAWN_SYSTEM);

        for (const auto &node : active_nodes) {
            sf::Packet old_players_packet;

            auto id = node->get_component<NameComponent>()->get_network_id();
            auto player_pos = node->get_component<CollisionComponent>()->get_body()->GetPosition();
            player_pos *= SCALE;

            old_players_packet << id << float(player_pos.x) << float(player_pos.y) << false;

            net->append(client, old_players_packet, SPAWN_SYSTEM);
        }
    }

    void on_client_disconnect(uint16_t client) override {
        //TODO а здесь надо рассылать данные о выходе клиента и удалении его сущности (net->append)
        for (const auto &node : active_nodes) {
            if (node->get_component<NameComponent>()->get_network_id() == client) {
                delete_entity(node->get_component<NameComponent>()->get_parent_id());
                sf::Packet disconnect_packet;
                disconnect_packet << node->get_component<NameComponent>()->get_network_id();
                net->append_all(disconnect_packet, UNSPAWN_SYSTEM);
                break;
            }
        }
    }

  private:
    ServerNetworkManager* net;
    std::map<uint16_t, Entity*> player_map;

};

#endif  // ACID_INCLUDE_SERVER_NETWORK_SPAWN_SYSTEM_H_
