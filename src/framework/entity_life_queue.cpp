#include <entity_life_queue.h>

void EntityLifeQueue::add_entity(Entity *entity) {
    add_queue.push(entity);
}

void EntityLifeQueue::delete_entity(uint16_t type_id, uint16_t id) {
    delete_queue.push(std::make_pair(type_id, id));
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

std::pair<uint16_t, uint16_t> EntityLifeQueue::get_delete() {
    if (!delete_queue.empty()) {
        auto temp = delete_queue.front();
        delete_queue.pop();
        return temp;
    } else {
        return std::make_pair(0, 0);
    }
}
