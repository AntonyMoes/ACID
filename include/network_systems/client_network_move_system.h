//
// Created by vladimir on 03.12.18.
//

#ifndef A_C_I_D_CLIENT_NETWORK_MOVE_SYSTEM_H
#define A_C_I_D_CLIENT_NETWORK_MOVE_SYSTEM_H

#include <network_id.h>
#include <active_system.h>
#include <network_manager.h>
#include <unistd.h>

class NetworkMoveSystem: public ActiveSystem<None> {
public:
    explicit NetworkMoveSystem( NetworkManager* _net): net(_net) {
    }
    void execute() final{
        usleep(40000);

        sf::Packet& received_packet = net->get_system_packet(MOVE_SYSTEM_ID);
        if (!received_packet.endOfPacket()) {
            int x, y;
            received_packet >> x >> y;
            //TODO - это стоит вынести в отдельный класс-фабрику
            std::cout << x << " "<< y << std::endl;
        }
        sf::Packet packet_to_send;
        packet_to_send << int(4) << int(2);
        net->append(packet_to_send, MOVE_SYSTEM_ID);
    }
private:
    NetworkManager* const net;
};
#endif //A_C_I_D_CLIENT_NETWORK_MOVE_SYSTEM_H
