#include <game_loop.h>

GameLoop::GameLoop() {
    init();
}

void GameLoop::terminate() {
    is_enabled = false;
}

void GameLoop::run() {
    while(is_enabled) {
        cycle();
        process_lifetime();
    }
}

void GameLoop::init() {

}

void GameLoop::cycle() {
    for (const auto &item : systems) {
        item->run();
    }

}

GameLoop::~GameLoop() {
    for (auto &system : systems) {
        delete system;
    }
}

void GameLoop::process_lifetime() {
    size_t id = 0;
    Entity* entity = nullptr;

    while ((id = queue.get_delete()) != 0) {
        e_manager.delete_entity(id);
    }

    while ((entity = queue.get_add()) != nullptr) {
        e_manager.add_entity(entity);
    }
}

void GameLoop::add_prototype(INode *node) {
    n_manager.add_prototype(node);
}

EntityLifeQueue *GameLoop::get_queue_ref() {
    return &queue;
}

void GameLoop::add_system(BaseSystem *system) {
    systems.push_back(system);
}
