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

    ~GraphicSystem() = default;

    void execute() const override {
        if (active_nodes.empty()) {
            return;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window->close();
            }
        auto cam_node = active_nodes.front();
        auto cam_coord_comp = cam_node->get_component<PositionComponent>();
        sf::Vector2f center = cam_coord_comp->get_coords();
        sf::Vector2u window_size = window->getSize();

        auto drawable_objects = camera->get_scope(center, window_size.x, window_size.y);
        for (const auto& obj: drawable_objects) {
            sf::Vector2f pos = obj.first;
            std::cout << "x: " << pos.x << " y: " << pos.y << std::endl;
            sf::Sprite sprite = obj.second->get_sprite();
            sprite.setPosition(pos);
            sprite.move(pos);
            window->draw(sprite);
        }
    }

  private:
    sf::RenderWindow* window;
    CameraSystem* camera;
};


#endif  // ACID_INCLUDE_DRAW_SYSTEM_H_
