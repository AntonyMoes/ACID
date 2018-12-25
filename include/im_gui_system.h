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
        static char windowTitle[255] = "ImGui + SFML =!";
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

        if (ImGui::Button("Exit game")) {
            // этот код выполняется, когда юзер жмёт на кнопку
            // здесь можно было бы написать
            // if(ImGui::InputText(...))
            window->close();
        }

        ImGui::End(); // end window

        ImGui::BeginMainMenuBar();
        ImGui::EndMainMenuBar();

        bool a = true;
        ImGui::SetNextWindowPos({0, 0});
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
        ImGui::Begin("Hoba", &a, ImGuiWindowFlags_NoCollapse || ImGuiWindowFlags_NoTitleBar);
        //ImGui::Spacing();
            auto size = ImGui::GetIO().DisplaySize;
            auto height = size.y;
            auto width = size.x;
            for (size_t i = 0; i < height/40; ++i) {
                ImGui::Text("\n");
            }
            for (size_t i = 0; i < width/32; ++i) {
                ImGui::Text(" ");
                ImGui::SameLine();
            }
            ImGui::PushItemWidth(120);
            ImGui::InputText("IP", windowTitle, 16);
            for (size_t i = 0; i < width/32; ++i) {
                ImGui::Text(" ");
                ImGui::SameLine();
            }
            if (ImGui::InputText("Port", windowTitle, 16)) {
                std::cout << "wow\n";
            }

            for (size_t i = 0; i < width/32; ++i) {
                ImGui::Text(" ");
                ImGui::SameLine();
            }
            if (ImGui::Button("     Connect     ")) {
                window->setTitle(windowTitle);
            }
        ImGui::PopItemWidth();
        ImGui::End();


    }

  private:
    sf::RenderWindow* window;
    sf::Clock deltaClock;
};

#endif  // ACID_INCLUDE_IM_GUI_SYSTEM_H_
