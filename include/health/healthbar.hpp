#ifndef ACID_INCLUDE_HEALTHBAR_H_
#define ACID_INCLUDE_HEALTHBAR_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#include <active_system.h>
#include <hp_node.hpp>
#include <texture_manager.h>

class Healthbar : public ActiveSystem<HPNode> {
  public:
    explicit Healthbar(sf::RenderWindow* window, TextureManager* tm):
    window(window),
    tm(tm) {
        lvl_font.loadFromFile("../fonts/ProggyTiny.ttf");
    }

    ~Healthbar() override = default;

    void execute() override {
        sf::Texture htx;
        sf::Sprite health;
        sf::Sprite mana;
        sf::Sprite exp_sprite;
        sf::Text lvl_text;
        auto node = *active_nodes.begin();
        if(node != nullptr) {
                auto *h_comp = node->get_component<HealthComponent>();
                auto hp = h_comp->get_hp();
                auto max_hp = h_comp->get_max_hp();
                health.setTexture(*tm->getHP(hp, max_hp));

                auto *m_comp = node->get_component<ManaComponent>();
                auto sp = m_comp->get_mana();
                auto max_sp = m_comp->get_max_mana();
                mana.setTexture(*tm->getMP(sp, max_sp));

                auto *e_comp = node->get_component<ExpComponent>();
                auto ep = e_comp->get_tmp_exp();
                auto max_ep = e_comp->get_exp_before_up();
                exp_sprite.setTexture(*tm->getHP(ep, max_ep));

                std::string lvl("LVL: ");
                lvl.append(std::to_string(e_comp->get_level()));
                lvl_text.setString(lvl);
        }
        health.setScale(sf::Vector2f(0.5f, 0.5f));
        mana.setScale(sf::Vector2f(0.5f, 0.5f));
        exp_sprite.setScale(sf::Vector2f(0.5f, 0.5f));

        auto screen = window->getSize();
        mana.setPosition(sf::Vector2f(0, 65));
        exp_sprite.setPosition(sf::Vector2f(0, 130));

        sf::View hpView(sf::Vector2f(screen.x / 2, screen.y / 2), sf::Vector2f(screen.x, screen.y));
        sf::View defaultView = window->getView();
        window->setView(hpView);
        window->draw(health);
        window->draw(mana);
        window->draw(exp_sprite);







        lvl_text.setFont(lvl_font);
        lvl_text.setCharacterSize(50); // in pixels, not points!

        // set th
        lvl_text.setPosition(60, 200);
        window->draw(lvl_text);

        window->setView(defaultView);
    }

  private:
    sf::RenderWindow* window;
    TextureManager* tm;
    sf::Font lvl_font;
};

#endif  // ACID_INCLUDE_HEALTHBAR_H_
