#ifndef ACID_INCLUDE_SERVER_NETWORK_MOVE_SYSTEM_H_
#define ACID_INCLUDE_SERVER_NETWORK_MOVE_SYSTEM_H_

#include <server_network_manager.h>
#include <network_id.h>
#include <active_system.h>
#include <server_player.h>
#include <server_pos_sync_node.h>

class ServerNetworkMoveSystem: public ActiveSystem<ServerPosSyncNode> {
  public:
    explicit ServerNetworkMoveSystem(ServerNetworkManager* _net) : net(_net) { }
    void execute() final {
        //TODO: implementation needed

        for (auto node : active_nodes) {
            auto cl_id = node->get_component<NameComponent>()->get_network_id();
            sf::Packet& p =net->get_received_data(cl_id, MOVE_SYSTEM_ID);
            while (!p.endOfPacket()) {
                float x = 0;
                float y = 0;
                p >> x >> y;
                node->get_component<CollisionComponent>()->get_body()->SetTransform(b2Vec2(x, y), 0);
                sf::Packet sp;
                sp << cl_id << x << y;
                net->append_all(sp, MOVE_SYSTEM_ID);
            }

        }
    }

  private:
    ServerNetworkManager* const net;
};

#endif  // ACID_INCLUDE_SERVER_NETWORK_MOVE_SYSTEM_H_
