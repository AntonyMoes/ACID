#include <entity_life_queue.h>

void EntityLifeQueue::add_entity(Entity *entity) {
    add_queue.push(entity);
}

void EntityLifeQueue::delete_entity(unsigned int id) {
    delete_queue.push(id);
}

Entity *EntityLifeQueue::get_add() {
    if (!add_queue.empty()) {
        auto temp = add_queue.front();
        add_queue.pop();
        return temp;
    } else {
        return nullptr;
    }
}

size_t EntityLifeQueue::get_delete() {
    if (!delete_queue.empty()) {
        auto temp = delete_queue.front();
        delete_queue.pop();
        return temp;
    } else {
        return 0;
    }
}
