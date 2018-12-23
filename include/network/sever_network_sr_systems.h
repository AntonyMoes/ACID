#ifndef ACID_INCLUDE_SEVER_NETWORK_SR_SYSTEMS_H_
#define ACID_INCLUDE_SEVER_NETWORK_SR_SYSTEMS_H_


#include <unistd.h>

#include <i_component.h>
#include <server_network_manager.h>
#include <active_system.h>
#include <chrono>
#include <thread>
class NetworkReceiveSystem : public ActiveSystem<NoneNode> {
  public:
    explicit NetworkReceiveSystem( ServerNetworkManager* _net): net(_net) {

    }
    void execute() {
        //TODO: adaptive
        auto next_frame = std::chrono::steady_clock::now();
        next_frame += std::chrono::milliseconds(1000 / 60);

        net->process_events();

        std::this_thread::sleep_until(next_frame);

    }

  private:
    ServerNetworkManager* const net;
};


class NetworkSendSystem: public ActiveSystem<NoneNode> {
  public:
    explicit NetworkSendSystem(ServerNetworkManager* _net): net(_net) {}
    void execute() final { net->send(); }

  private:
    ServerNetworkManager* const net;
};

#endif  // ACID_INCLUDE_SEVER_NETWORK_SR_SYSTEMS_H_
