#ifndef ACID_INCLUDE_ENTITY_LIFE_QUEUE_H_
#define ACID_INCLUDE_ENTITY_LIFE_QUEUE_H_


#include <queue>
#include "entity.h"

class EntityLifeQueue {
  public:
    EntityLifeQueue() = default;
    void add_entity(Entity* entity);
    void delete_entity(uint16_t type_id, uint16_t id);

    Entity* get_add();
    std::pair<uint16_t, uint16_t> get_delete();

  private:
    std::queue<Entity *> add_queue;
    std::queue<std::pair<uint16_t, uint16_t>> delete_queue;

};

#endif  // ACID_INCLUDE_ENTITY_LIFE_QUEUE_H_
