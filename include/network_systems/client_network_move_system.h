#ifndef ACID_INCLUDE_CLIENT_NETWORK_MOVE_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_NETWORK_MOVE_SYSTEM_H_

#include <network_id.h>
#include <active_system.h>
#include <network_manager.h>
#include <client_pos_sync_node.h>
#include <name_component.h>

class NetworkReceiveMoveSystem: public ActiveSystem<ClientPosSyncNode> {
  public:
    explicit NetworkReceiveMoveSystem( NetworkManager* _net): net(_net) {
    }
    void execute() final{
        //TODO: implementation needed
        sf::Packet& received_packet = net->get_system_packet(MOVE_SYSTEM_ID);
        while (!received_packet.endOfPacket()) {
            uint16_t id;
            float x = 0;
            float y = 0;

            received_packet >> id >> x >> y;

            CollisionComponent* collision_component;
            for (const auto &node : active_nodes) {
                if (node->get_component<NameComponent>()->get_network_id() == id) {
                    auto body = node->get_component<CollisionComponent>()->get_body();
                    if (body->GetType() == b2_staticBody) {
                        node->get_component<CollisionComponent>()->get_body()->SetTransform(b2Vec2(x, y), 0.0f);
                    }
                }
            }
        }
    }

  private:
    NetworkManager* const net;
};

class NetworkSendMoveSystem: public ActiveSystem<PlayerPosSyncNode> {
public:
    explicit NetworkSendMoveSystem( NetworkManager* _net): net(_net) {
    }
    void execute() final {

        for (const auto &node : active_nodes) {

            auto& pos = node->get_component<CollisionComponent>()->get_body()->GetPosition();
            float x = pos.x;
            float y = pos.y;
            sf::Packet packet_to_send;

            packet_to_send << x << y;
            net->append(packet_to_send, MOVE_SYSTEM_ID);
        }

    }

private:
    NetworkManager* const net;
};

#endif  // ACID_INCLUDE_CLIENT_NETWORK_MOVE_SYSTEM_H_
