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
#include <collision/collision_listener.h>
#include <entity_death_node.h>
#include <damage/damage_node.h>
#include <entity_death_system.h>
#include <projectile_lifetime_system.h>
#include <projectile_lifetime_node.h>
#include <graphic/tmx_level.h>
#include <physical_system.h>
#include <network_systems/server_death_synchroniztion_system.h>
#include <damage/damage_system.h>
#include <mana/mana_regen_system.h>
#include <skills/fireball_burst_system.h>
#include <generators/exp_creation_system.h>
#include <systems/exp_distribution_system.h>
#include <generators/exp_creation_node.h>
#include <nodes/exp_distribution_node.h>
#include <mana/mana_node.h>
#include <skills/skill_node.h>
#include <network_systems/client_health_sync_system.h>
#include <network_systems/server_health_sync_system.h>
#include <network_systems/server_health_sync_node.h>

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
    loop.add_prototype(new PlayerNode);
    loop.add_prototype(new ServerPosSyncNode());
    loop.add_prototype(new FireballDamageNode);
    loop.add_prototype(new FireballNode);
    loop.add_prototype(new EntityDeathNode);
    loop.add_prototype(new DamageNode);
    loop.add_prototype(new ProjectileLifetimeNode);
    loop.add_prototype(new DeathSyncNode);
    auto physic_system = new PhysicalSystem(world, level);
    auto projectile_lifetime_system = new ProjectileLifetimeSystem;
    auto entity_death_system = new EntityDeathSystem;

    NetworkSpawnSystem spawn_system(&net);
    NetworkReceiveSystem net_receive(&net);
    ServerNetworkMoveSystem net_move(&net);
    NetworkSendSystem net_send(&net);
    ServerShotSynchronizationSystem shot_sync(&net);
    ServerShotReceiveSystem shot_receive(&net);
    ServerDeathSyncSystem death_sync(&net);
    loop.add_system(physic_system);
    loop.add_system(&net_receive);
    loop.add_system(&shot_receive);
    loop.add_system(&net_move);
    loop.add_system(&net_send);
    loop.add_system(&spawn_system);
    loop.add_system(&shot_sync);
    loop.add_system(entity_death_system);
    loop.add_system(projectile_lifetime_system);
    loop.add_system(&death_sync);
    loop.register_life_system(entity_death_system);
    loop.register_life_system(&spawn_system);
    loop.register_life_system(&shot_receive);


    auto damage_system = new DamageSystem(loop.get_entity_manager());

    //auto mana_regen_system = new ManaRegenSystem;
    //auto fireball_burst_system = new FireballBurstSystem;

    //auto exp_creation_system = new ExpCreationSystem;
    //auto exp_distribution_system = new ExpDistributionSystem(loop.get_entity_manager());


    //auto exp_creation_node = new ExpCreationNode;
    //loop.add_prototype(exp_creation_node);

    //auto exp_distibution_node = new ExpDistributionNode;
    //loop.add_prototype(exp_distibution_node);

    auto* damage_node = new DamageNode;
    loop.add_prototype(damage_node);

    //auto mana_node = new ManaNode;
    //loop.add_prototype(mana_node);

    //auto skill_node = new SkillNode;
    //loop.add_prototype(skill_node);


    loop.add_system(damage_system);
    //loop.add_system(exp_creation_system);
    //loop.add_system(exp_distribution_system);
    //loop.add_system(mana_regen_system);
    //loop.add_system(fireball_burst_system);

    //loop.register_life_system(fireball_burst_system);

    //loop.register_life_system(exp_creation_system);
    //loop.register_life_system(exp_distribution_system);



    loop.add_system(new ServerHealthSyncSystem(&net));
    loop.add_prototype(new ServerHealthSyncNode);

    loop.run();



    return 0;
}