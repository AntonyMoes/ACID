#ifndef ACID_INCLUDE_SERVER_EXP_SYNC_SYSTEM_H_
#define ACID_INCLUDE_SERVER_EXP_SYNC_SYSTEM_H_


#include <reactive_system.h>
#include <network_id.h>
#include <server_network_manager.h>
#include <server_exp_sync_node.h>

class ServerExpSyncSystem: public ReactiveSystem<ServerExpSyncNode> {
  public:
    explicit ServerExpSyncSystem(ServerNetworkManager* net): net(net) {}

    void execute() override {
        for (auto& node : reactive_nodes) {
            sf::Packet packet;
            auto id = node->get_component<NameComponent>()->get_network_id();
            auto exp_comp = node->get_component<ExpComponent>();
            packet << id;
            net->append_all(packet, EXP_SYSTEM);
        }
    }

  private:
    ServerNetworkManager* net;
};

#endif   // ACID_INCLUDE_SERVER_EXP_SYNC_SYSTEM_H_
