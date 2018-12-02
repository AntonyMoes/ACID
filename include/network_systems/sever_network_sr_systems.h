//
// Created by vladimir on 03.12.18.
//

#ifndef A_C_I_D_SEVER_NETWORK_SR_SYSTEMS_H
#define A_C_I_D_SEVER_NETWORK_SR_SYSTEMS_H
#include <framework/i_component.h>

#include <server_network_manager.h>
#include <unistd.h>
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


#endif //A_C_I_D_SEVER_NETWORK_SR_SYSTEMS_H
