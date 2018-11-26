#ifndef ACID_CUSTOM_LOOP_H
#define ACID_CUSTOM_LOOP_H
#include <game_loop.h>
#include <graphic_system.h>
#include <camera_system.h>
#include <displayer_system.h>
#include <input_move_system.h>
#include <move_system.h>
#include <framework/test/test_activesystems_cycle.h>
#include "TmxLevel.h"
#include <map_draw_system.h>

class Loop : public GameLoop {
protected:
    sf::RenderWindow *window;
    TmxLevel level;
public:
    Loop(sf::RenderWindow *w) : window(w) { init();}
    void run() {
        while(window->isOpen()) {
            cycle();
            process_lifetime();
        }
    }
};

#endif //A_C_I_D_CUSTOM_LOOP_H
