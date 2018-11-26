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

    void execute() const override {
        if (active_nodes.empty()) {
            return;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window->close();
        }
        auto cam_node = *active_nodes.begin();
        auto cam_coord_comp = cam_node->get_component<PositionComponent>();
        sf::Vector2f center = cam_coord_comp->get_coords();
        std::cout << "x: " << center.x << " y: " << center.y << std::endl;

        sf::Vector2u window_size = window->getSize();

        auto drawable_objects = camera->get_scope(center, window_size.x, window_size.y);

        auto view = window->getView();
        view.setCenter(center.x, center.y);
        window->setView(view);

        for (const auto& obj: drawable_objects) {
            sf::Vector2f pos = obj.first;
            sf::Sprite sprite = obj.second->get_component<TextureComponent>()->get_sprite();
            sprite.setPosition(pos);
            window->draw(sprite);
        }
    }

  private:
    sf::RenderWindow* window;
    CameraSystem* camera;
};


#endif  // ACID_INCLUDE_DRAW_SYSTEM_H_
