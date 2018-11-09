#ifndef ACID_INCLUDE_ENTITY_LIFE_QUEUE_H_
#define ACID_INCLUDE_ENTITY_LIFE_QUEUE_H_


#include <queue>
#include "entity.h"

class EntityLifeQueue {
  public:
    EntityLifeQueue() = default;
    void add_entity(Entity* entity);
    void delete_entity(unsigned int id);

    Entity* get_add();
    size_t get_delete();

  private:
    std::queue<Entity *> add_queue;
    std::queue<size_t> delete_queue;

};

#endif  // ACID_INCLUDE_ENTITY_LIFE_QUEUE_H_
