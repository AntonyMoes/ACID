#include <framework/i_component.h>
#include <node.h>
#include <entity_life_system.h>
#include <framework/game_loop.h>
#include <network_manager.h>
#include <map>
#include <unistd.h>
#include <active_system.h>
class None {

};
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
class NetworkReceiveSystem : public ActiveSystem<None> {
public:
    NetworkReceiveSystem( NetworkManager* _net): net(_net) {

    }
    void execute() {
        usleep(40000);

        net->receive();
        sf::Packet& p = net->get_system_packet(1);
        if (!p.endOfPacket()) {
            int x, y;
            p >> x >> y;
            std::cout << x << " "<< y;
        }
        sf::Packet sp;
        sp << 4 << 2;
        net->append(sp, 1);

        net->send();
    }
private:
    NetworkManager* const net;
};

class NetworkSpawnSystem : public EntityLifeSystem {
public:
    explicit NetworkSpawnSystem(NetworkManager* _net): net(_net) { }
    void execute() {
        usleep(40000);

    }

private:
    NetworkManager* net;
    std::map<uint16_t, Entity*> player_map;

};


int main() {
    GameLoop loop;
    NetworkManager net;
    net.connect("localhost", 55503);
    loop.add_prototype(new PlayerNode());

    NetworkSpawnSystem spawn_system(&net);
    NetworkReceiveSystem net_receive(&net);
    loop.register_life_system(&spawn_system);
    loop.add_system(&net_receive);

    loop.run();

    return 0;
}