//
// Created by vladimir on 03.12.18.
//

#ifndef A_C_I_D_CLIENT_NETWORK_SPAWN_SYSTEM_H
#define A_C_I_D_CLIENT_NETWORK_SPAWN_SYSTEM_H
#include <framework/i_component.h>
#include <entity_life_system.h>

#include <network_manager.h>

#include <active_system.h>
#include <network_id.h>

class NetworkSpawnSystem : public EntityLifeSystem {
public:
    explicit NetworkSpawnSystem(NetworkManager* _net): net(_net) { }
    void execute() {

    }

private:
    NetworkManager* net;
    std::map<uint16_t, Entity*> player_map;

};

#endif //A_C_I_D_CLIENT_NETWORK_SPAWN_SYSTEM_H
