#ifndef ACID_INCLUDE_DRAW_SYSTEM_H_
#define ACID_INCLUDE_DRAW_SYSTEM_H_


#include <active_system.h>
#include <camera_system.h>
#include <graphic_node.h>
#include <camera_node.h>
#include <cmath>
class GraphicSystem: public ActiveSystem<CameraNode> {
  public:
    GraphicSystem(sf::RenderWindow* window, CameraSystem* camera):
    window(window),
    camera(camera) {
        if (!font.loadFromFile("../fonts/ProggyTiny.ttf")) {
            throw std::bad_alloc();
        }
        text.setFont(font);
        text.setString("YOU DIED!");
        text.setCharacterSize(100);
        //text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
    }

    void execute() override {
        if (active_nodes.empty()) {
            auto view = window->getView();
            view.setCenter(-2000.1f, -2000.1f);
            window->setView(view);
            text.setOrigin(450, 50);
            text.setPosition(-1690.1f, -2000.1f);
            window->draw(text);
            return;
        }
        auto cam_node = *active_nodes.begin();
        auto cam_col_comp = cam_node->get_component<CollisionComponent>();
        auto body = cam_col_comp->get_body();
        b2Vec2 body_pos = body->GetPosition();
        body_pos *= SCALE;
        // TODO: use this to adjust main entity's position when access to entity through \
                            node will be implemented
        //auto body_size = cam_node->get_component<TextureComponent>()->get_sprite().getTexture()->getSize();

        sf::Vector2u window_size = window->getSize();

        auto drawable_objects = camera->get_scope(body_pos, window_size.x, window_size.y);

        auto view = window->getView();
        view.setCenter(floor(body_pos.x) + 0.01, floor(body_pos.y) + 0.01);
        window->setView(view);

        for (const auto& obj: drawable_objects) {
            b2Vec2 pos = obj.second->get_component<CollisionComponent>()->get_body()->GetPosition();
            pos *= SCALE;
            sf::Sprite sprite = obj.second->get_component<TextureComponent>()->get_sprite();
            auto size = sprite.getScale();
            sf::Vector2f sf_pos(pos.x, pos.y);
            sprite.setPosition(sf_pos);
            window->draw(sprite);
        }
    }

  private:
    sf::RenderWindow* window;
    CameraSystem* camera;
    sf::Font font;
    sf::Text text;
};

#endif  // ACID_INCLUDE_DRAW_SYSTEM_H_
