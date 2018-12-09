//
// Created by vladimir on 07.12.18.
//

#ifndef A_C_I_D_CLIENT_SHOT_SYCHRONIZATION_SYSTEM_H
#define A_C_I_D_CLIENT_SHOT_SYCHRONIZATION_SYSTEM_H

#include <reactive_system.h>
#include <active_system.h>
#include <fireball_creation_node.h>
#include <network_manager.h>

class ClientShotReceiveSystem : ActiveSystem<FireballCreationNode>{
  public:
    explicit ClientShotReceiveSystem(NetworkManager* _net): net(_net) {

    }
    void execute() final {

    }


  private:
    NetworkManager* net;
};

class ClientShotSendSystem
#endif //A_C_I_D_CLIENT_SHOT_SYCHRONIZATION_SYSTEM_H
