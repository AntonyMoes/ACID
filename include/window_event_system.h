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
        if (window->pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            if (event.type == sf::Event::Resized) {
                auto view = window->getView();
                sf::Vector2u size = window->getSize();
                view.setSize(size.x, size.y);
                window->setView(view);
            }
        }
    }

private:
    sf::RenderWindow* window;
};

#endif  // ACID_INCLUDE_WINDOW_EVENT_SYSTEM_H_