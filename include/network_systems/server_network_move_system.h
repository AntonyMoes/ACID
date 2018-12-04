#ifndef ACID_INCLUDE_SERVER_NETWORK_MOVE_SYSTEM_H_
#define ACID_INCLUDE_SERVER_NETWORK_MOVE_SYSTEM_H_

#include <server_network_manager.h>
#include <network_id.h>
#include <active_system.h>
#include <server_pos_sync_node.h>


class ServerNetworkMoveSystem: public ActiveSystem<ServerPosSyncNode> {
  public:
    explicit ServerNetworkMoveSystem(ServerNetworkManager* _net) : net(_net) { }
    void execute() final {
        //TODO: implementation needed
        /*(for (auto n : active_nodes) {
            auto cl_id = n->get_component<PlayerComponent>()->get_network_id();
            sf::Packet& p =net->get_received_data(cl_id, MOVE_SYSTEM_ID);
            sf::Packet ps;
            ps  << 1 << 2;
            net->append(cl_id, ps, MOVE_SYSTEM_ID);
            if (!p.endOfPacket()) {
                int x, y;
                p >> x >> y;
                std::cout << x << " "<< y << std::endl;
            }
        }*/
    }

  private:
    ServerNetworkManager* const net;
};

#endif  // ACID_INCLUDE_SERVER_NETWORK_MOVE_SYSTEM_H_
