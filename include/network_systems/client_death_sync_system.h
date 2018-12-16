//
// Created by vladimir on 17.12.18.
//

#ifndef A_C_I_D_CLIENT_DEATH_SYNC_SYSTEM_H
#define A_C_I_D_CLIENT_DEATH_SYNC_SYSTEM_H


#include <network_manager.h>
#include <framework/active_system.h>
#include <network_id.h>
#include <framework/entity_manager.h>

class NoneNode {

};
class ClientDeathSyncSystem : public ActiveSystem<NoneNode> {
  public:
    ClientDeathSyncSystem(NetworkManager* _net, EntityManager* _entity_manager) :
                entity_manager(_entity_manager), net(_net) {

    }
    void execute() override {
        auto packet = net->get_system_packet(DEATH_SYSTEM);
        while (!packet.endOfPacket()) {
            uint16_t id;
            packet >> id;
            entity_manager->delete_entity(id);
        }
    }
  private:
    NetworkManager* net;
    EntityManager* entity_manager;
};

#endif //A_C_I_D_CLIENT_DEATH_SYNC_SYSTEM_H
