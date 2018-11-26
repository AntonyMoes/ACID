//
// Created by sava on 25.11.18.
//

#ifndef ACID_MAP_DRAW_SYSTEM_H
#define ACID_MAP_DRAW_SYSTEM_H
#include <active_system.h>
#include "TmxLevel.h"

class MapSystem : public ActiveSystem<None> {
 public:
    MapSystem(sf::RenderWindow* window, TmxLevel &level):
    window(window),
    level(level) {}

    ~MapSystem() = default;

    void execute() const override {
        level.Draw(*window);
    }

private:
    sf::RenderWindow* window;
    TmxLevel level;
};
#endif //ACID_MAP_DRAW_SYSTEM_H
