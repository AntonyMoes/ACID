#ifndef ACID_INCLUDE_CLIENT_HEALTH_SYNC_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_HEALTH_SYNC_SYSTEM_H_


#include <network_id.h>
#include <active_system.h>
#include <network_manager.h>
#include <client_health_sync_node.h>

class ClientHealthSyncSystem: public ActiveSystem<ClientHealthSyncNode> {
  public:
    explicit ClientHealthSyncSystem(NetworkManager* net): net(net) {}

    void execute() override {
        sf::Packet& received_packet = net->get_system_packet(HEALTH_SYSTEM);
        while (!received_packet.endOfPacket()) {
            uint16_t id = 0;
            int hp = 0;

            received_packet >> id >> hp;
            for (const auto &node : active_nodes) {
                if (node->get_component<NameComponent>()->get_network_id() == id) {
                    auto health_comp = node->get_component<HealthComponent>();
                    health_comp->set_hp(hp);
                }
            }
        }
    }

  private:
    NetworkManager* net;
};

#endif  // ACID_INCLUDE_CLIENT_HEALTH_SYNC_SYSTEM_H_
