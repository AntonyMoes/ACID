#ifndef ACID_INCLUDE_SEVER_NETWORK_SR_SYSTEMS_H_
#define ACID_INCLUDE_SEVER_NETWORK_SR_SYSTEMS_H_

#include <unistd.h>

#include <i_component.h>
#include <server_network_manager.h>
#include <active_system.h>


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


class NetworkSendSystem: public ActiveSystem<None> {
  public:
    explicit NetworkSendSystem(ServerNetworkManager* _net): net(_net) {}
    void execute() final { net->send(); }

  private:
    ServerNetworkManager* const net;
};

#endif  // ACID_INCLUDE_SEVER_NETWORK_SR_SYSTEMS_H_
