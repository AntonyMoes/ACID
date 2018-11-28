#include <framework/i_component.h>
#include <node.h>
#include <entity_life_system.h>
#include <framework/game_loop.h>
#include <network_manager.h>

class PlayerComponent: public IComponent {
  public:
    std::string& get_nick();
    void set_nick(const std::string& _nick);
  private:
    std::string nick;
};

class PlayerNode : public Node <PlayerNode> {
    PlayerNode() {
        add_component<PlayerComponent>();
    }
};

class NetworkSpawnSystem : public EntityLifeSystem {
    pu
    NetworkSpawnSystem(NetworkManager* _net) {

    }

};

int main() {
    GameLoop loop;
    NetworkSpawnSystem spawn_system;
    loop.register_life_system(&spawn_system);

    return 0;
}