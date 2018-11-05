#ifndef ACID_INCLUDE_ENTITY_LIFE_QUEUE_H_
#define ACID_INCLUDE_ENTITY_LIFE_QUEUE_H_


class EntityLifeQueue {
  public:
    EntityLifeQueue();
    void add_entity(unsigned short type, unsigned int id = 0);
    void delete_entity(unsigned int id);
};

#endif  // ACID_INCLUDE_ENTITY_LIFE_QUEUE_H_
