//
// Created by vladimir on 07.12.18.
//

#ifndef A_C_I_D_CLIENT_SHOT_SYCHRONIZATION_SYSTEM_H
#define A_C_I_D_CLIENT_SHOT_SYCHRONIZATION_SYSTEM_H

#include <reactive_system.h>
#include <active_system.h>
#include <fireball_creation_node.h>
#include <network_manager.h>
#include <network_id.h>
#include <framework/entity_life_system.h>
#include <projectile.h>
#include <input_mouse_node.h>

class ClientShotReceiveSystem : public ActiveSystem<FireballCreationNode>, public EntityLifeSystem {
  public:
    explicit ClientShotReceiveSystem(NetworkManager* _net): net(_net) {

    }
    void execute() final {
        sf::Packet& packet = net->get_system_packet(FIRE_SYSTEM_ID);
        while (!packet.endOfPacket()) {
            uint16_t id = 0;
            float x = 0;
            float y = 0;
            float sx = 0;
            float sy = 0;
            packet >> id >> x >> y >> sx >> sy;
            auto projectile = new Projectile(b2Vec2(x, y), b2Vec2(sx, sy));
            projectile->set_id(id);
            create_entity(projectile);
        }
    }

  private:
    NetworkManager* net;
};


class ClientShotSendSystem : public ReactiveSystem<InputMouseNode> {
public:
    explicit ClientShotSendSystem(NetworkManager* _net): net(_net) {

    }
    void execute() final {
        auto node = *reactive_nodes.begin();
        if (node) {
            auto pos = node->get_component<InputMouseComponent>()->get_mouse_pos();
            sf::Packet packet;
            packet << pos.x << pos.y;
            std::cout << reactive_nodes.size() << std::endl;
            net->append(packet, FIRE_SYSTEM_ID);
        }

    }

private:
    NetworkManager* net;
};
#endif //A_C_I_D_CLIENT_SHOT_SYCHRONIZATION_SYSTEM_H
