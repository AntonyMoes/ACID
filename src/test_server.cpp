#include <framework/i_component.h>
#include <node.h>
#include <entity_life_system.h>
#include <framework/game_loop.h>
#include <server_network_manager.h>

class PlayerComponent: public IComponent {
public:
    const std::string& get_nick();
    void set_nick(const std::string& _nick);
private:
    std::string nick;
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

class NetworkSpawnSystem : public EntityLifeSystem {
  public:
    explicit NetworkSpawnSystem(ServerNetworkManager* _net): net(_net) { }
    void execute() {

    }
  private:
    ServerNetworkManager* net;
};

int main() {
    GameLoop loop;
    ServerNetworkManager net;
    loop.add_prototype(new PlayerNode());

    NetworkSpawnSystem spawn_system(&net);
    loop.register_life_system(&spawn_system);

    loop.run();

    return 0;
}