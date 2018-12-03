//
// Created by vladimir on 03.12.18.
//

#ifndef A_C_I_D_SERVER_NETWORK_SPAWN_SYSTEM_H
#define A_C_I_D_SERVER_NETWORK_SPAWN_SYSTEM_H

#include <framework/i_component.h>
#include <entity_life_system.h>

#include <server_network_manager.h>

#include <unistd.h>
#include <active_system.h>
#include <network_id.h>

class NetworkSpawnSystem : public EntityLifeSystem, private IClientObserver {
public:
    explicit NetworkSpawnSystem(ServerNetworkManager* _net): net(_net) { net->register_observer(this); }
    void execute() {
        usleep(40000);
    }
    void on_client_connect(uint16_t client) override {
        //TODO здесь надо рассылать данные о входе клиента и создании его сущности (net->append)
        /*std::cout << "connected" << std::endl;
        auto entity = new Entity();
        auto pc = new PlayerComponent();
        pc->set_network_id(client);
        entity->add_component(pc);
        player_map[client] = entity;
        create_entity(entity);*/
    }
    void on_client_disconnect(uint16_t client) override {
        //TODO а здесь надо рассылать данные о выходе клиента и удалении его сущности (net->append)
        /*std::cout << "disconnected" << std::endl;
        delete_entity(player_map[client]->get_id());
        player_map.erase(client);*/
    }

private:
    ServerNetworkManager* net;
    std::map<uint16_t, Entity*> player_map;

};

#endif //A_C_I_D_SERVER_NETWORK_SPAWN_SYSTEM_H
