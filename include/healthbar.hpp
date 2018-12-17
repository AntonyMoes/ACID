//
// Created by sava on 16.12.18.
//

#ifndef ACID_HEALTHBAR_H
#define ACID_HEALTHBAR_H
#include <active_system.h>
#include <hp_node.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <graphic/texture_manager.h>
class Healthbar : public ActiveSystem<HPNode> {
 public:
    explicit Healthbar(sf::RenderWindow* window, TextureManager* tm):
        window(window), tm(tm) {}

    ~Healthbar() override = default;

    void execute() override {
        sf::Texture htx;
        sf::Sprite health;
        sf::Sprite mana;
        auto node = *active_nodes.begin();
        if(node != nullptr) {
                auto *h_comp = node->get_component<HealthComponent>();
                auto hp = h_comp->get_hp();
                auto max_hp = h_comp->get_max_hp();
                health.setTexture(*tm->getHP(hp, max_hp));
                auto *m_comp = node->get_component<ManaComponent>();
                auto sp = m_comp->get_mana();
                auto max_sp = m_comp->get_max_mana();
                mana.setTexture(*tm->getHP(sp, max_sp));

        }
        health.setScale(sf::Vector2f(0.5f, 0.5f));
        mana.setScale(sf::Vector2f(0.5f, 0.5f));

        auto screen = window->getSize();
        mana.setPosition(sf::Vector2f(0, 50));
        sf::View hpView(sf::Vector2f(screen.x / 2, screen.y / 2), sf::Vector2f(screen.x, screen.y));
        sf::View defaultView = window->getView();
        window->setView(hpView);
        window->draw(health);
        window->draw(mana);
        window->setView(defaultView);
    }

 private:
    sf::RenderWindow* window;
    TextureManager* tm;
};
#endif //ACID_HEALTHBAR_H
