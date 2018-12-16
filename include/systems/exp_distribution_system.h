#ifndef ACID_INCLUDE_EXP_DISTRIBUTION_SYSTEM_H_
#define ACID_INCLUDE_EXP_DISTRIBUTION_SYSTEM_H_


#include <reactive_system.h>
#include <entity_life_system.h>
#include <exp_distribution_node.h>
#include <entity_manager.h>
#include <exp_component.h>

class ExpDistributionSystem: public ReactiveSystem<ExpDistributionNode>, public EntityLifeSystem {
  public:
    explicit ExpDistributionSystem(EntityManager* e_manager): e_manager(e_manager) {}

    void execute() override {
        for (auto& node : reactive_nodes) {
            auto collision_comp = node->get_component<CollisionComponent>();
            auto entity = e_manager->get_entity(collision_comp->get_collide_id());
            if (entity) {
                auto exp_comp = entity->get_component<ExpComponent>();
                if (exp_comp) {
                    auto drop_exp_comp = node->get_component<DropExpComponent>();
                    exp_comp->add_exp(drop_exp_comp->get_exp());
                    std::cout << "Сожрал экспу\n";
                    delete_entity(collision_comp->get_parent_id());
                }
            }
        }
    }

  private:
    EntityManager* e_manager;
};

#endif   // ACID_INCLUDE_EXP_DISTRIBUTION_SYSTEM_H_
