//
// Created by vladimir on 07.12.18.
//

#ifndef A_C_I_D_SERVER_SHOT_SYNCHRONIZTION_SYSTEM_H
#define A_C_I_D_SERVER_SHOT_SYNCHRONIZTION_SYSTEM_H

#include <framework/reactive_system.h>
#include <network_id.h>
#include <server_network_manager.h>
#include <projectile.h>
#include <entity_life_system.h>
#include <server_pos_sync_node.h>
#include <active_system.h>

class FireballNode: public Node<FireballNode> {
  public:
    FireballNode() {
        add_component<DamageComponent>();
        add_component<CollisionComponent>();
        add_component<BodyComponent>();
    }
};

class FireballDamageNode: public Node<FireballDamageNode> {
  public:
    FireballDamageNode() {
        add_component<NameComponent>();
        add_component<CollisionComponent>();
    }
};

class ServerShotSynchronizationSystem: public ReactiveSystem<FireballNode>{
  public:
    explicit ServerShotSynchronizationSystem(ServerNetworkManager* _net): net(_net) {

    }
    void execute() final {

    };
    void on_node_create(FireballNode* node) final {

        auto collision_component = node->get_component<CollisionComponent>();
        auto id = collision_component->get_parent_id();
        auto& pos = collision_component->get_body()->GetPosition();
        auto& speed = collision_component->get_body()->GetLinearVelocity();
        sf::Packet packet;
        packet << id << pos.x << pos.y << speed.x << speed.y;
        //TODO: send in scope only
        net->append_all(packet, FIRE_SYSTEM_ID);
    }

  private:
    ServerNetworkManager* net;
};

class ServerShotReceiveSystem: public ActiveSystem<FireballDamageNode>, public EntityLifeSystem {
  public:
    explicit ServerShotReceiveSystem(ServerNetworkManager* _net): net(_net) {

    }
    void execute() final {
        for (auto node : active_nodes) {
            auto id = node->get_component<NameComponent>()->get_network_id();
            auto packet = net->get_received_data(id, FIRE_SYSTEM_ID);
            while (!packet.endOfPacket()) {
                float x = 0;
                float y = 0;
                packet >> x >> y;
                auto pos = node->get_component<CollisionComponent>()->get_body()->GetPosition();
                auto direction = b2Vec2(x, y);
                ACIDMath::get_unit_b2Vec2(direction);
                b2Vec2 real_pos {pos.x + direction.x * 30, pos.y + direction.y * 30};
                auto projectile = new ServerProjectile(real_pos, direction);
                create_entity(projectile);
            }

        }

    }
  private:
    ServerNetworkManager* net;
};
#endif //A_C_I_D_SERVER_SHOT_SYNCHRONIZTION_SYSTEM_H
