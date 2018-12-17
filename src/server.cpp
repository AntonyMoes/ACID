#include <map>
#include <unistd.h>

#include <i_component.h>
#include <node.h>
#include <entity_life_system.h>
#include <game_loop.h>
#include <network/server_network_manager.h>
#include <active_system.h>
#include <network/network_id.h>
#include <server_network_move_system.h>
#include <sever_network_sr_systems.h>
#include <server_network_spawn_system.h>
#include <server_network_move_system.h>
#include <server_shot_synchroniztion_system.h>
#include <collision/collision_listener.h>
#include <entity_death_node.h>
#include <damage/damage_node.h>
#include <entity_death_system.h>
#include <projectile/projectile_lifetime_system.h>
#include <projectile/projectile_lifetime_node.h>
#include <graphic/tmx_level.h>
#include <physical_system.h>
#include <death/server_death_synchroniztion_system.h>
#include <damage/damage_system.h>
#include <mana/mana_regen_system.h>
#include <skills/fireball_burst_system.h>
#include <generators/exp_creation_system.h>
#include <exp/exp_distribution_system.h>
#include <generators/exp_creation_node.h>
#include <exp/exp_distribution_node.h>
#include <mana/mana_node.h>
#include <skills/skill_node.h>
#include <health/client_health_sync_system.h>
#include <health/server_health_sync_system.h>
#include <health/server_health_sync_node.h>
#include <server_exp_sync_system.h>
#include <server_exp_sync_node.h>
#include <mana/mana_sync_node.h>
#include <mana/server_network_mana_system.h>
#include <server_expball_sync_node.h>
#include <server_expball_sync_system.h>
#include <exp_creation_system.h>
#include <exp_creation_node.h>

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
    tmx_level level;
    try {
        level.LoadFromFile("../res/map.tmx");
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    auto* world = SingleWorld::get_instance();
    world->SetContactListener(new CollisionListener());

    GameLoop loop(true);
    ServerNetworkManager net(55503);

    loop.add_prototype(new ManaSyncNode);
    loop.add_prototype(new ManaNode);
    loop.add_prototype(new PlayerNode);
    loop.add_prototype(new ServerPosSyncNode());
    loop.add_prototype(new FireballDamageNode);
    loop.add_prototype(new FireballNode);
    loop.add_prototype(new EntityDeathNode);
    loop.add_prototype(new DamageNode);
    loop.add_prototype(new ProjectileLifetimeNode);
    loop.add_prototype(new DeathSyncNode);
    loop.add_prototype(new ServerExpSyncNode);
    loop.add_prototype(new ExpCreationNode);
    loop.add_prototype(new ServerExpBallSyncNode);

    auto mana_sync_system = new ServerNetworkManaSystem(&net);
    auto mana_regen_system = new ManaRegenSystem;
    auto physic_system = new PhysicalSystem(world, level);
    auto projectile_lifetime_system = new ProjectileLifetimeSystem;
    auto entity_death_system = new EntityDeathSystem;
    auto expball_create_system = new ExpCreationSystem;

    auto spawn_system = new NetworkSpawnSystem(&net);
    auto net_receive = new NetworkReceiveSystem(&net);
    auto net_move = new ServerNetworkMoveSystem(&net);
    auto net_send = new NetworkSendSystem(&net);
    auto shot_sync = new ServerShotSynchronizationSystem(&net);
    auto shot_receive = new ServerShotReceiveSystem(&net);
    auto death_sync = new ServerDeathSyncSystem(&net);
    auto exp_sync_system = new ServerExpSyncSystem(&net);
    auto expball_sync_system = new ServerExpBallSyncSystem(&net);

    
    loop.add_system(physic_system);
    loop.add_system(net_receive);
    loop.add_system(mana_sync_system);
    loop.add_system(mana_regen_system);
    loop.add_system(shot_receive);
    loop.add_system(net_move);
    loop.add_system(net_send);
    loop.add_system(spawn_system);
    loop.add_system(shot_sync);
    loop.add_system(entity_death_system);
    loop.add_system(projectile_lifetime_system);
    loop.add_system(expball_create_system);
    loop.add_system(expball_sync_system);
    loop.add_system(death_sync);
    loop.add_system(exp_sync_system);

    loop.register_life_system(entity_death_system);
    loop.register_life_system(expball_create_system);
    loop.register_life_system(spawn_system);
    loop.register_life_system(shot_receive);


    auto damage_system = new DamageSystem(loop.get_entity_manager());

    auto* damage_node = new DamageNode;
    loop.add_prototype(damage_node);

    loop.add_system(damage_system);

    loop.add_system(new ServerHealthSyncSystem(&net));
    loop.add_prototype(new ServerHealthSyncNode);

    loop.run();



    return 0;
}