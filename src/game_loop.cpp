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
    }
}

void GameLoop::init() {

}

void GameLoop::cycle() {
    for (const auto &item : systems) {
        // TODO(AntonyMoes): implement
    }
}

GameLoop::~GameLoop() {
    for (auto &system : systems) {
        delete system;
    }
}
