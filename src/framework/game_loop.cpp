#include <game_loop.h>
#include <iostream>
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
    std::pair<uint16_t, uint16_t> id = {0, 0};
    auto zero_pair = id;
    Entity* entity = nullptr;
    
    while ((id = queue.get_delete()) != zero_pair) {
        e_manager.delete_entity(id.first, id.second);
    }

    while ((entity = queue.get_add()) != nullptr) {
        e_manager.add_entity(entity);
    }
}

void GameLoop::add_prototype(INode *node) {
    n_manager.add_prototype(node);
}
void GameLoop::add_system(BaseSystem *system) {
    systems.push_back(system);
}
