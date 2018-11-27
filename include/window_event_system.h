#ifndef ACID_INCLUDE_WINDOW_EVENT_SYSTEM_H_
#define ACID_INCLUDE_WINDOW_EVENT_SYSTEM_H_


#include <SFML/Graphics/RenderWindow.hpp>

#include <framework/active_system.h>
#include <framework/terminator_system.h>

class WindowEventSystem : public ActiveSystem<None>, public TerminatorSystem {
public:
    explicit WindowEventSystem(sf::RenderWindow* window):
            window(window) {}

    void execute() const override {
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();

        }
    }

private:
    sf::RenderWindow* window;
};

#endif  // ACID_INCLUDE_WINDOW_EVENT_SYSTEM_H_