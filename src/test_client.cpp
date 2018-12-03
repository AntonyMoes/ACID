#include <map>
#include <unistd.h>

#include <framework/i_component.h>
#include <node.h>
#include <entity_life_system.h>
#include <framework/game_loop.h>
#include <network_manager.h>
#include <active_system.h>
#include <network_id.h>

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


class NetworkSendSystem: public ActiveSystem<None> {
  public:
    explicit NetworkSendSystem(NetworkManager* _net): net(_net) {}
    void execute() final { net->send(); }

  private:
    NetworkManager* const net;
};


class NetworkReceiveSystem : public ActiveSystem<None> {
  public:
    explicit NetworkReceiveSystem( NetworkManager* _net): net(_net) {
    }
    void execute() final{ net->receive(); }

  private:
    NetworkManager* const net;
};

//TODO: Эта ситема отвечает за синхронизацию преремещения по сети, для нее нужна нода
class NetworkMoveSystem: public ActiveSystem<None> {
  public:
    explicit NetworkMoveSystem( NetworkManager* _net): net(_net) {}
    void execute() final{
        usleep(40000);

        sf::Packet& received_packet = net->get_system_packet(MOVE_SYSTEM_ID);
        if (!received_packet.endOfPacket()) {
            int x, y;
            received_packet >> x >> y;
            //TODO - это стоит вынести в отдельный класс-фабрику
            std::cout << x << " "<< y << std::endl;
        }
        sf::Packet packet_to_send;
        packet_to_send << int(4) << int(2);
        net->append(packet_to_send, MOVE_SYSTEM_ID);
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
};


int main() {
    GameLoop loop;
    NetworkManager net;
    net.connect("localhost", 55503);
    loop.add_prototype(new PlayerNode());

    NetworkSpawnSystem spawn_system(&net);
    //Система для выполнения приема данных. Добавляется ПЕРВОЙ
    NetworkReceiveSystem net_receive(&net);
    //Система(пример) для синхронизации перемещения по сети
    NetworkMoveSystem net_move(&net);
    //Система для отправки данных. Добавляется ПОСЛЕДНЕЙ
    NetworkSendSystem net_send(&net);

    loop.register_life_system(&spawn_system);
    loop.add_system(&net_receive);
    loop.add_system(&net_move);
    loop.add_system(&net_send);

    loop.run();

    return 0;
}