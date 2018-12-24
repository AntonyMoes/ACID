//
// Created by antonymo on 24.12.18.
//

#ifndef A_C_I_D_SKILL_LVLUP_SYSTEM_H
#define A_C_I_D_SKILL_LVLUP_SYSTEM_H

#include <framework/active_system.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <imgui/imgui-SFML.h>
#include <imgui/imgui.h>
#include "input_skill_node.h"
#include "skill_component.h"
#include "skill_lvlup_node.h"

class SkillLvlupSystem : public ActiveSystem<SkillLvlupNode> {
public:
    explicit SkillLvlupSystem(sf::RenderWindow* window) : window(window) {}

    void execute() final {
        ImGui::SFML::Update(*window, deltaClock.restart());
        auto input_skill_node = *active_nodes.begin();
        if (!input_skill_node) {
                return;
        }
        auto inp = input_skill_node->get_component<InputSkillComponent>();
        static bool a;
        a = (*(inp->get_keys()))[sf::Keyboard::K];
        //std::cout << a << std::endl;

        //if ((*inp->get_keys())[sf::Keyboard::K]) {
        //    a = !a;
        //}



        if (a) {
            ImGui::SetNextWindowSize({250, 100});
            ImGui::Begin("Upgrades", &a, ImGuiWindowFlags_NoCollapse || ImGuiWindowFlags_NoResize);
            auto skill_comp = input_skill_node->get_component<SkillComponent>();
            auto points = skill_comp->get_skill_points();
            std::string title = "Current points: " + std::to_string(points);
            ImGui::Text(title.c_str());

            auto hp_comp = input_skill_node->get_component<HpRegenComponent>();
            auto hp_regen = hp_comp->get_hp_regen_rate();
            std::string curr_hp_regen = "Curr hp regen: " + std::to_string(hp_regen);
            ImGui::Text(curr_hp_regen.c_str());
            ImGui::SameLine();
            if (ImGui::Button("Upgrade HP")) {
                if (points > 0) {
                    skill_comp->dispence_skill_point(1);
                    hp_comp->lvlup();
                    skill_comp->set_skill_updated(SkillComponent::skill::hp);
                }
            }


            auto mana_comp = input_skill_node->get_component<ManaComponent>();
            auto mp_regen = mana_comp->get_regen_rate();
            std::string curr_mp_regen = "Curr mp regen: " + std::to_string(mp_regen);
            ImGui::Text(curr_mp_regen.c_str());
            ImGui::SameLine();
            if (ImGui::Button("Upgrade MP")) {
                if (points > 0) {
                    skill_comp->dispence_skill_point(1);
                    mana_comp->set_regen_rate(mp_regen + 5);
                    skill_comp->set_skill_updated(SkillComponent::skill::mana);
                }
            }


           // auto skill_comp = input_skill_node->get_component<SkillComponent>();
            auto fireballs = skill_comp->get_burst_lvl() + 4;
            std::string curr_fireballs = "Curr burst fireballs: " + std::to_string(fireballs);
            ImGui::Text(curr_fireballs.c_str());
            ImGui::SameLine();
            if (ImGui::Button("Upgrade Burst")) {
                if (points > 0 && skill_comp->get_burst_lvl() < skill_comp->get_burst_max_lvl()) {
                    skill_comp->dispence_skill_point(1);
                    skill_comp->lvl_up_burst();
                    skill_comp->lvl_up_burst();
                    skill_comp->set_skill_updated(SkillComponent::skill::burst);
                }
            }

            ImGui::End();
        }


        (*(inp->get_keys()))[sf::Keyboard::K] = a;

    }

private:
    sf::RenderWindow* window;
    sf::Clock deltaClock;
};

#endif //A_C_I_D_SKILL_LVLUP_SYSTEM_H
