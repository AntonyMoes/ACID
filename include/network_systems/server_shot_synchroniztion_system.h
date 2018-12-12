//
// Created by vladimir on 07.12.18.
//

#ifndef A_C_I_D_SERVER_SHOT_SYNCHRONIZTION_SYSTEM_H
#define A_C_I_D_SERVER_SHOT_SYNCHRONIZTION_SYSTEM_H

#include <framework/reactive_system.h>
#include <fireball_creation_node.h>
#include <network_id.h>
#include <server_network_manager.h>
#include <projectile.h>
#include <entity_life_system.h>
//TODO это не EntityLifeQ
class ServerShotSynchronizationSystem: public ReactiveSystem<FireballCreationNode>, public EntityLifeSystem {
  public:
    explicit ServerShotSynchronizationSystem(ServerNetworkManager* _net): net(_net) {

    }
    void execute() final {
        static int i =0;
        i++;
        if (i == 500) {
            auto projectile = new Projectile(b2Vec2(0,0), b2Vec2(100, 100));
            create_entity(projectile);

        }

    }
    void on_node_create(FireballCreationNode* node) final {
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
#endif //A_C_I_D_SERVER_SHOT_SYNCHRONIZTION_SYSTEM_H
