#include <map>
#include <unistd.h>

#include <i_component.h>
#include <node.h>
#include <entity_life_system.h>
#include <game_loop.h>
#include <server_network_manager.h>
#include <active_system.h>
#include <network_id.h>
#include <server_network_move_system.h>
#include <sever_network_sr_systems.h>
#include <server_network_spawn_system.h>
#include <server_network_move_system.h>
#include <server_shot_synchroniztion_system.h>
#include <collision_listener.h>
#include <entity_death_node.h>
#include <damage_node.h>
#include <entity_death_system.h>
#include <projectile_lifetime_system.h>
#include <projectile_lifetime_node.h>
class PlayerComponent: public IComponent {
  public:
    const std::string& get_nick();
    void set_nick(const std::string& _nick);
    void set_network_id(uint16_t  _network_id) { network_id = _network_id; }
    uint16_t get_network_id() { return network_id; }

  private:
    std::string nick;
    uint16_t network_id;
};

void PlayerComponent::set_nick(const std::string &_nick) {
    nick = _nick;
    update();
}

const std::string& PlayerComponent::get_nick() {
    return nick;
}


class PlayerNode : public Node <PlayerNode> {
  public:
    PlayerNode() {
        add_component<PlayerComponent>();
    }
};

int main() {
    GameLoop loop(true);
    ServerNetworkManager net(55503);
    loop.add_prototype(new PlayerNode);
    loop.add_prototype(new ServerPosSyncNode());
    loop.add_prototype(new FireballDamageNode);
    loop.add_prototype(new FireballNode);
    loop.add_prototype(new EntityDeathNode);
    loop.add_prototype(new DamageNode);
    loop.add_prototype(new ProjectileLifetimeNode);

    auto projectile_lifetime_system = new ProjectileLifetimeSystem;
    auto entity_death_system = new EntityDeathSystem;

    NetworkSpawnSystem spawn_system(&net);
    NetworkReceiveSystem net_receive(&net);
    ServerNetworkMoveSystem net_move(&net);
    NetworkSendSystem net_send(&net);
    ServerShotSynchronizationSystem shot_sync(&net);
    ServerShotReceiveSystem shot_receive(&net);
    auto* world = SingleWorld::get_instance();
    world->SetContactListener(new CollisionListener());
    loop.add_system(&net_receive);
    loop.add_system(&shot_receive);
    loop.add_system(&net_move);
    loop.add_system(&net_send);
    loop.add_system(&spawn_system);
    loop.add_system(&shot_sync);
    loop.add_system(entity_death_system);
    loop.add_system(projectile_lifetime_system);

    loop.register_life_system(entity_death_system);
    loop.register_life_system(&spawn_system);
    loop.register_life_system(&shot_receive);
    loop.run();

    return 0;
}