#ifndef ACID_INCLUDE_SERVER_HEALTH_SYNC_SYSTEM_H_
#define ACID_INCLUDE_SERVER_HEALTH_SYNC_SYSTEM_H_


#include <network_id.h>
#include <reactive_system.h>
#include <server_health_sync_node.h>
#include <server_network_manager.h>

class ServerHealthSyncSystem: public ReactiveSystem<ServerHealthSyncNode> {
  public:
    explicit ServerHealthSyncSystem(ServerNetworkManager* net) : net(net) {}

    void execute() override {
        for (const auto& send_player : reactive_nodes) {
            auto id = send_player->get_component<NameComponent>()->get_network_id();
            auto hp = send_player->get_component<HealthComponent>()->get_hp();
            sf::Packet packet;
            packet << id << hp;
            net->append(id, packet, HEALTH_SYSTEM);
        }
    }

  private:
    ServerNetworkManager* net;
};

#endif  // ACID_INCLUDE_SERVER_HEALTH_SYNC_SYSTEM_H_
