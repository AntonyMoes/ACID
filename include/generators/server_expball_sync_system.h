#ifndef ACID_INCLUDE_SERVER_EXPBALL_SYNC_SYSTEM_H_
#define ACID_INCLUDE_SERVER_EXPBALL_SYNC_SYSTEM_H_



#include <reactive_system.h>
#include <entity_life_system.h>
#include <server_expball_sync_node.h>
#include <server_network_manager.h>
#include <exp_ball.h>
#include <network_id.h>

class ServerExpBallSyncSystem: public ReactiveSystem<ServerExpBallSyncNode> {
  public:
    explicit ServerExpBallSyncSystem(ServerNetworkManager* net): net(net) {}

    void execute() override {

    }

    void on_node_create(ServerExpBallSyncNode* node) final {
        auto drop_exp_comp = node->get_component<DropExpComponent>();
        auto body_comp = node->get_component<BodyComponent>();

        auto pos = body_comp->get_body()->GetPosition();
        auto exp = drop_exp_comp->get_exp();
        auto id = drop_exp_comp->get_parent_id();

        sf::Packet packet;
        packet << id << pos.x << pos.y << exp;
        net->append_all(packet, EXPBALL_SYSTEM);
    }

  private:
    ServerNetworkManager* net;
};

#endif   // ACID_INCLUDE_SERVER_EXPBALL_SYNC_SYSTEM_H_
