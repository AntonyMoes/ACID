//
// Created by sava on 16.12.18.
//

#ifndef ACID_HEALTHBAR_H
#define ACID_HEALTHBAR_H
#include <active_system.h>
#include <hp_node.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <texture_manager.h>
class Healthbar : public ActiveSystem<HPNode> {
 public:
    explicit Healthbar(sf::RenderWindow* window, TextureManager* tm):
        window(window), tm(tm) {}

    ~Healthbar() override = default;

    void execute() override {
        sf::Texture htx;
            sf::Sprite health;
            auto node = *active_nodes.begin();
            if(node != nullptr) {
                auto *player = node->get_component<HealthComponent>();
                auto hp = player->get_hp();
                auto max_hp = player->get_max_hp();
                health.setTexture(*tm->getHP(hp, max_hp));
        }
        health.setScale(sf::Vector2f(0.5f, 0.5f));
        auto screen = window->getSize();

        sf::View hpView(sf::Vector2f(screen.x / 2, screen.y / 2), sf::Vector2f(screen.x, screen.y));
        sf::View defaultView = window->getView();
        window->setView(hpView);
        window->draw(health);
        window->setView(defaultView);
    }

 private:
    sf::RenderWindow* window;
    TextureManager* tm;
};
#endif //ACID_HEALTHBAR_H
