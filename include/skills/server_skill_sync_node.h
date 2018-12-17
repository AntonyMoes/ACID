#ifndef ACID_SERVER_SKILL_SYNC_NODE_H_
#define ACID_SERVER_SKILL_SYNC_NODE_H_


#include <framework/node.h>
#include <mana/mana_component.h>
#include <entities/body_component.h>

class ServerSkillSyncNode : public Node<ServerSkillSyncNode> {
  public:
    ServerSkillSyncNode() {
        add_component<NameComponent>();
        add_component<ManaComponent>();
        add_component<CollisionComponent>();
    }
};

#endif //A_C_I_D_SERVER_SKILL_SYNC_NODE_H
