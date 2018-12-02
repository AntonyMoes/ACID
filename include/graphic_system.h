#ifndef ACID_INCLUDE_DRAW_SYSTEM_H_
#define ACID_INCLUDE_DRAW_SYSTEM_H_


#include <active_system.h>
#include <camera_system.h>
#include <graphic_node.h>
#include <camera_node.h>


class GraphicSystem: public ActiveSystem<CameraNode> {
  public:
    GraphicSystem(sf::RenderWindow* window, CameraSystem* camera):
    window(window),
    camera(camera) {}

    void execute() override {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window->close();
        }
        if (active_nodes.empty()) {
            return;
        }
        auto cam_node = *active_nodes.begin();
        auto cam_col_comp = cam_node->get_component<CollisionComponent>();
        auto body = cam_col_comp->get_body();
        b2Vec2 body_pos = body->GetPosition();

        //std::cout << "x: " << center.x << " y: " << center.y << std::endl;

        sf::Vector2u window_size = window->getSize();

        auto drawable_objects = camera->get_scope(body_pos, window_size.x, window_size.y);

        auto view = window->getView();
        view.setCenter(body_pos.x, body_pos.y);
        window->setView(view);

        for (const auto& obj: drawable_objects) {
            b2Vec2 pos = obj.second->get_component<CollisionComponent>()->get_body()->GetPosition();
            std::cout << "x: " << pos.x << " y: " << pos.y << std::endl;
            sf::Vector2f sf_pos(pos.x, pos.y);
            sf::Sprite sprite = obj.second->get_component<TextureComponent>()->get_sprite();
            sprite.setPosition(sf_pos);
            window->draw(sprite);
        }
    }

  private:
    sf::RenderWindow* window;
    CameraSystem* camera;
};


#endif  // ACID_INCLUDE_DRAW_SYSTEM_H_
