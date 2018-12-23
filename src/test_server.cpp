#include <map>
#include <unistd.h>

#include <framework/i_component.h>
#include <node.h>
#include <entity_life_system.h>
#include <framework/game_loop.h>
#include <network/server_network_manager.h>
#include <active_system.h>
#include <network/network_id.h>


class PlayerComponent: public IComponent {
  public:
    const std::string& get_nick();
    void set_nick(const std::string& _nick);
    void set_network_id(uint16_t _network_id) { network_id = _network_id; }
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


class NetworkReceiveSystem : public ActiveSystem<None> {
  public:
    explicit NetworkReceiveSystem( ServerNetworkManager* _net): net(_net) {

    }
    void execute() {
        usleep(40000);
        net->process_events();
    }

  private:
     ServerNetworkManager* const net;
};


class TestMoveSystem: public ActiveSystem<PlayerNode> {
  public:
    explicit TestMoveSystem(ServerNetworkManager* _net) : net(_net) { }
    void execute() final {
        for (auto n : active_nodes) {
            auto cl_id = n->get_component<PlayerComponent>()->get_network_id();

            /*sf::Packet& p =net->get_received_data(cl_id, MOVE_SYSTEM_ID);
            sf::Packet ps;
            ps  << 1 << 2;
            net->append(cl_id, ps, MOVE_SYSTEM_ID);
            if (!p.endOfPacket()) {
                int x, y;
                p >> x >> y;
                std::cout << x << " "<< y << std::endl;
            }*/
        }
    }

  private:
    ServerNetworkManager* const net;
};


class NetworkSpawnSystem : public EntityLifeSystem, private IClientObserver {
  public:
    explicit NetworkSpawnSystem(ServerNetworkManager* _net): net(_net) { net->register_observer(this); }
    void execute() {
        usleep(40000);
    }
    void on_client_connect(uint16_t client) override {
        //TODO здесь надо рассылать данные о входе клиента и создании его сущности (net->append)
        std::cout << "connected" << std::endl;
        auto entity = new Entity();
        auto pc = new PlayerComponent();
        pc->set_network_id(client);
        entity->add_component(pc);
        player_map[client] = entity;
        create_entity(entity);
    }
    void on_client_disconnect(uint16_t client) override {
        //TODO а здесь надо рассылать данные о выходе клиента и удалении его сущности (net->append)
        std::cout << "disconnected" << std::endl;
        delete_entity(player_map[client]->get_id());
        player_map.erase(client);
    }

  private:
    ServerNetworkManager* net;

};


class NetworkSendSystem: public ActiveSystem<None> {
  public:
    explicit NetworkSendSystem(ServerNetworkManager* _net): net(_net) {}
    void execute() final { net->send(); }

  private:
    ServerNetworkManager* const net;
};

int main() {
    GameLoop loop;
    ServerNetworkManager net(55503);
    loop.add_prototype(new PlayerNode());

    NetworkSpawnSystem spawn_system(&net);
    NetworkReceiveSystem net_receive(&net);
    NetworkSendSystem net_send(&net);

    loop.add_system(&net_receive);
    loop.add_system(new TestMoveSystem(&net));
    loop.add_system(&net_send);
    loop.register_life_system(&spawn_system);
    loop.run();

    return 0;
}