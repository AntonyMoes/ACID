#ifndef ACID_INCLUDE_CLIENT_EXP_SYNC_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_EXP_SYNC_SYSTEM_H_


#include <active_system.h>
#include <network_manager.h>
#include <entity_manager.h>
#include <client_exp_sync_node.h>
#include <network_id.h>

class ClientExpSyncNode: public ActiveSystem<ClientExpSyncNode> {
  public:
    explicit ClientExpSyncNode(NetworkManager* net): net(net) {}

    void execute() override {
        auto packet = net->get_system_packet(EXP_SYSTEM);
        while (!packet.endOfPacket()) {
            uint16_t id;
            packet >> id;

            for (auto& node : active_nodes) {
                if (node->get_component<NameComponent>()->get_network_id() == id) {

                }
            }
        }
    }

  private:
    NetworkManager* net;
};

#endif   // ACID_INCLUDE_CLIENT_EXP_SYNC_SYSTEM_H_
