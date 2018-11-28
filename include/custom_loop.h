#ifndef ACID_INCLUDE_CUSTOM_LOOP_H_
#define ACID_INCLUDE_CUSTOM_LOOP_H_

#include <game_loop.h>
#include <graphic_system.h>
#include <camera_system.h>
#include <displayer_system.h>
#include <input_move_system.h>
#include <move_system.h>
#include <framework/test/test_activesystems_cycle.h>
#include "tmx_level.h"
#include <map_draw_system.h>


class Loop : public GameLoop {
  public:
    Loop(sf::RenderWindow *w) : window(w) { init();}
    void run() {
        while(window->isOpen()) {
            cycle();
            process_lifetime();
        }
    }

  protected:
    sf::RenderWindow *window;
    tmx_level level;
};

#endif  // ACID_INCLUDE_CUSTOM_LOOP_H_
