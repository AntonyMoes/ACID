#ifndef ACID_INCLUDE_DISPLAYER_SYSTEM_H_
#define ACID_INCLUDE_DISPLAYER_SYSTEM_H_


#include <SFML/Graphics.hpp>
#include <active_system.h>


// TODO(Antony): отныне и вовеки веков переместить это в фреймворк

class None {};

class DisplayerSystem: public ActiveSystem<None> {
  public:
    DisplayerSystem(sf::RenderWindow* window):
    window(window) {}

    void execute() const override {
        window->display();
        window->clear();
    }

  private:
    sf::RenderWindow* window;
};

#endif  // ACID_INCLUDE_DISPLAYER_SYSTEM_H_
