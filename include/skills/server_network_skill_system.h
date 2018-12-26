#ifndef A_C_I_D_SERVER_NETWORK_SKILL_SYSTEM_H
#define A_C_I_D_SERVER_NETWORK_SKILL_SYSTEM_H


#include <network/server_network_manager.h>
#include <framework/active_system.h>
#include <entities/name_component.h>
#include <network/network_id.h>
#include <ACID_math.h>
#include <entities/projectile.h>
#include <framework/entity_life_system.h>
#include "server_skill_sync_node.h"

static uint16_t burst_mana = 10;

class ServerNetworkSkillSystem : public ActiveSystem<ServerSkillSyncNode>, public EntityLifeSystem {
public:
    explicit ServerNetworkSkillSystem(ServerNetworkManager* _net) : net(_net) { }
    void execute() override {
        for (auto node : active_nodes) {
            auto cl_id = node->get_component<NameComponent>()->get_network_id();
            if (!node->get_component<NameComponent>()->is_player()) {
                continue;
            }
            sf::Packet& p =net->get_received_data(cl_id, SKILL_SYSTEM);
            while (!p.endOfPacket()) {
                bool do_we_burst = false;
                p >> do_we_burst;
                if (do_we_burst) {
                    auto mana_comp = node->get_component<ManaComponent>();
                    auto mana = mana_comp->get_mana();
                    if (mana >= burst_mana) {
                        mana -= burst_mana;
                        mana_comp->set_mana(mana);

                        auto pos = node->get_component<CollisionComponent>()->get_body()->GetPosition();
                        pos *= SCALE;

                        int ang_inc = 360 / (node->get_component<SkillComponent>()->get_burst_lvl() + 4);
                        for (int ang = 0; ang < 360; ang += ang_inc) {
                            auto direction = ACIDMath::get_b2Vec_from_angle(ang);
                            b2Vec2 real_pos{pos.x + direction.x * 40, pos.y + direction.y * 40};
                            create_entity(new Projectile(real_pos, direction));
                        }
                    }
                }
            }
        }
    }

private:
    ServerNetworkManager* net;
};

#endif //A_C_I_D_SERVER_NETWORK_SKILL_SYSTEM_H


