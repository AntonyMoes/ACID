#ifndef ACID_INCLUDE_DISPLAYER_SYSTEM_H_
#define ACID_INCLUDE_DISPLAYER_SYSTEM_H_


#include <SFML/Graphics.hpp>

#include <active_system.h>
#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>


// TODO(Antony): отныне и вовеки веков переместить это в фреймворк


class DisplayerSystem: public ActiveSystem<NoneNode> {
  public:
    DisplayerSystem(sf::RenderWindow* window):
    window(window) {}

    void execute() override {
        ImGui::SFML::Render(*window);
        window->display();
        window->clear();
    }

  private:
    sf::RenderWindow* window;
};

#endif  // ACID_INCLUDE_DISPLAYER_SYSTEM_H_
