#ifndef ACID_INCLUDE_SERVER_NETWORK_SPAWN_SYSTEM_H_
#define ACID_INCLUDE_SERVER_NETWORK_SPAWN_SYSTEM_H_


#include <unistd.h>

#include <entity_life_system.h>
#include <server_player.h>
#include <server_pos_sync_node.h>
#include <server_network_manager.h>
#include <active_system.h>
#include <network_id.h>
#include <enemy_component.h>
#include <graphic_constants.h>

class NetworkSpawnSystem : public ActiveSystem<ServerPosSyncNode>, public EntityLifeSystem, private IClientObserver {
  public:
    explicit NetworkSpawnSystem(ServerNetworkManager* _net): net(_net) { net->register_observer(this); }
    void execute() {
        static uint16_t i = 600;

        if (i % 600 == 0) {
            float x = std::rand() % 5000;
            float y = std::rand() % 3700;
            auto enemy = new ServerPlayer(i, x, y, false);
            enemy->get_component<NameComponent>()->set_network_id(i);
            enemy->get_component<CollisionComponent>()->get_body()->SetType(b2_staticBody);
            enemy->add_component(new EnemyComponent());
            sf::Packet enemy_spawn_packet;
            enemy_spawn_packet << i << x << y << false << ENEMY_TEXTURE;
            net->append_all(enemy_spawn_packet, SPAWN_SYSTEM);
            create_entity(enemy);
        }
        i++;
    }

    void on_client_connect(uint16_t client) override {
        //TODO здесь надо рассылать данные о входе клиента и создании его сущности (net->append)
        static float pos = 10;
        for (const auto& send_player : active_nodes) {
            sf::Packet spawn_packet;
            spawn_packet << client << pos << pos << false;
            net->append(send_player->get_component<NameComponent>()->get_network_id(), spawn_packet, SPAWN_SYSTEM);
        }
        auto player = new ServerPlayer(client, pos, pos, true);
        player->get_component<NameComponent>()->set_network_id(client);
        create_entity(player);
        sf::Packet client_spawn_packet;
        client_spawn_packet << client << pos << pos << true << PLAYER_TEXTURE;

        pos += 50;

        net->append(client, client_spawn_packet, SPAWN_SYSTEM);


        for (const auto &node : active_nodes) {
            sf::Packet old_players_packet;
            auto id = node->get_component<NameComponent>()->get_network_id();
            auto player_pos = node->get_component<CollisionComponent>()->get_body()->GetPosition();
            player_pos *= SCALE;
            int texture = PLAYER_TEXTURE;
            if (!node->get_component<NameComponent>()->is_player()) {
                texture = ENEMY_TEXTURE;
            }
            old_players_packet << id << float(player_pos.x) << float(player_pos.y) << false << texture;

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
