#ifndef ACID_INCLUDE_CLIENT_EXP_SYNC_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_EXP_SYNC_SYSTEM_H_


#include <active_system.h>
#include <network_manager.h>
#include <entity_manager.h>
#include <client_exp_sync_node.h>
#include <network_id.h>

class ClientExpSyncSystem: public ActiveSystem<ClientExpSyncNode> {
  public:
    explicit ClientExpSyncSystem(NetworkManager* net): net(net) {}

    void execute() override {
        auto packet = net->get_system_packet(EXP_SYSTEM);
        while (!packet.endOfPacket()) {
            uint16_t id = 0;
            uint16_t lvl = 0;
            uint16_t tmp_exp = 0;
            uint16_t exp_before_up = 0;
            uint16_t exp_for_death = 0;
            float lvlup_coef = 0.0f;
            float death_exp_coef = 0.0f;
            packet >> id >> lvl >> tmp_exp >> exp_before_up >> exp_for_death;
            packet >> lvlup_coef >> death_exp_coef;

            for (auto& node : active_nodes) {
                if (node->get_component<NameComponent>()->get_network_id() == id) {
                    auto exp_comp = node->get_component<ExpComponent>();
                    exp_comp->set_level(lvl);
                    exp_comp->set_tmp_exp(tmp_exp);
                    exp_comp->set_exp_before_up(exp_before_up);
                    exp_comp->set_exp_for_death(exp_for_death);
                    exp_comp->set_lvlup_coef(lvlup_coef);
                    exp_comp->set_death_exp_coef(death_exp_coef);
                    break;
                }
            }
        }
    }

  private:
    NetworkManager* net;
};

#endif   // ACID_INCLUDE_CLIENT_EXP_SYNC_SYSTEM_H_
