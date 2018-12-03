#include <network_manager.h>
#include <active_system.h>

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

