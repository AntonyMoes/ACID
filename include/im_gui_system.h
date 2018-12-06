#ifndef ACID_INCLUDE_IM_GUI_SYSTEM_H_
#define ACID_INCLUDE_IM_GUI_SYSTEM_H_

#include <framework/active_system.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

class NONE{};

class ImGuiSystem : public ActiveSystem<NONE> {
  public:
    explicit ImGuiSystem(sf::RenderWindow* window) : window(window) {}

    void execute() final {
        static sf::Color bgColor;
        static float color[3] = { 0.f, 0.f, 0.f };

        // здесь мы будем использовать массив char. Чтобы использовать
        // std::string нужно сделать действия, описанные во второй части
        static char windowTitle[255] = "ImGui + SFML = <3";
        //window->setTitle(windowTitle);



        ImGui::SFML::Update(*window, deltaClock.restart());

        ImGui::Begin("Sample window"); // создаём окно

        // Инструмент выбора цвета
        if (ImGui::ColorEdit3("Background color", color)) {
            // код вызывается при изменении значения, поэтому всё
            // обновляется автоматически
            bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
            bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
            bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
        }

        ImGui::InputText("Window title", windowTitle, 255);

        if (ImGui::Button("Update window title")) {
            // этот код выполняется, когда юзер жмёт на кнопку
            // здесь можно было бы написать
            // if(ImGui::InputText(...))
            window->setTitle(windowTitle);
        }


        ImGui::End(); // end window

        //bool q = false;
        //if (!q) {
        ImGui::Begin("Wanna quit?"/*, &q, ImVec2{50.f, 50.f}*/);
        if (ImGui::Button("Exit game")) {
            // этот код выполняется, когда юзер жмёт на кнопку
            // здесь можно было бы написать
            // if(ImGui::InputText(...))
            window->close();
        }
        ImGui::End();
        //}


        //window->clear(bgColor); // заполняем окно заданным цветом
        //ImGui::SFML::Render(*window);
        //window->display();


        ImGui::SFML::Render(*window);
        window->display();
        window->clear(bgColor);


    }

  private:
    sf::RenderWindow* window;
    sf::Clock deltaClock;
};

#endif  // ACID_INCLUDE_IM_GUI_SYSTEM_H_
