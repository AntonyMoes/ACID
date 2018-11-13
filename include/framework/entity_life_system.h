//
// Created by antonymo on 13.11.18.
//

#ifndef ACID_INCLUDE_FRAMEWORK_ENTITY_LIFE_SYSTEM_H_
#define ACID_INCLUDE_FRAMEWORK_ENTITY_LIFE_SYSTEM_H_


#include <i_system.h>
#include <entity_life_queue.h>

class EntityLifeSystem {
  public:
    EntityLifeSystem() = default;
    ~EntityLifeSystem() = default;

    void set_queue(EntityLifeQueue* q) {
        queue = q;
    }

    void create_entity(Entity* entity) const {
        queue->add_entity(entity);
    }

    void delete_entity(size_t id) const {
        queue->delete_entity(id);
    }

  private:
    EntityLifeQueue* queue = nullptr;


};

#endif  // ACID_INCLUDE_FRAMEWORK_ENTITY_LIFE_SYSTEM_H_
