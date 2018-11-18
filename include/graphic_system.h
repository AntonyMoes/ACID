#ifndef ACID_INCLUDE_DRAW_SYSTEM_H_
#define ACID_INCLUDE_DRAW_SYSTEM_H_


#include <active_system.h>
#include <camera_system.h>
#include <graphic_node.h>
#include <camera_node.h>


class GraphicalSystem: public ActiveSystem<CameraNode> {
  public:
    GraphicalSystem(sf::RenderWindow* window, CameraSystem* camera):
    window(window),
    camera(camera) {}

    ~GraphicalSystem() = default;

    void execute() const override {
        auto cam_node = active_nodes.front();
        auto cam_coord_comp = cam_node->get_component<PositionComponent>();
        sf::Vector2f center = cam_coord_comp->get_coords();
        sf::Vector2u window_size = window->getSize();

        drawable_objects = camera->get_scope(center, window_size.x, window_size.y);
        for (const auto& obj: drawable_objects) {
            sf::Vector2f pos = obj.first;
            sf::Sprite sprite = obj.second->get_sprite();
            sprite.setPosition(pos);
            sprite.move(pos);
            window.draw(sprite);
        }
    }

  private:
    std::vector<std::pair<sf::Vector2f, TextureComponent*>> drawable_objects;
    sf::RenderWindow* window;
    CameraSystem* camera;
};


#endif  // ACID_INCLUDE_DRAW_SYSTEM_H_
