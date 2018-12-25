#ifndef ACID_INCLUDE_CUSTOM_LOOP_H_
#define ACID_INCLUDE_CUSTOM_LOOP_H_

#include <game_loop.h>
#include <graphic/graphic_system.h>
#include <camera/camera_system.h>
#include <graphic/displayer_system.h>
#include <input_move_system.h>
#include <movements/move_system.h>
#include <graphic/tmx_level.h>
#include <graphic/map_draw_system.h>
#include <physical_system.h>


class Loop : public GameLoop {
  public:
    Loop(sf::RenderWindow *w, bool is_server) : GameLoop(is_server), window(w) { init();}
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
