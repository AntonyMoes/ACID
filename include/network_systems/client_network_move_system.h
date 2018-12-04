#ifndef ACID_INCLUDE_CLIENT_NETWORK_MOVE_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_NETWORK_MOVE_SYSTEM_H_

#include <unistd.h>

#include <network_id.h>
#include <active_system.h>
#include <network_manager.h>
#include <client_pos_sync_node.h>


class NetworkMoveSystem: public ActiveSystem<ClientPosSyncNode> {
  public:
    explicit NetworkMoveSystem( NetworkManager* _net): net(_net) {
    }
    void execute() final{

        sf::Packet& received_packet = net->get_system_packet(MOVE_SYSTEM_ID);
        if (!received_packet.endOfPacket()) {
            uint16_t id;
            int x, y;
            received_packet >> id >> x >> y;

            PositionComponent* pos_comp;
            for (const auto &node : active_nodes) {
                //if (node->get_component<PositionComponent>())
            }

            std::cout << x << " "<< y << std::endl;
        }
        sf::Packet packet_to_send;
        packet_to_send << int(4) << int(2);
        net->append(packet_to_send, MOVE_SYSTEM_ID);
    }

  private:
    NetworkManager* const net;
};

#endif  // ACID_INCLUDE_CLIENT_NETWORK_MOVE_SYSTEM_H_
