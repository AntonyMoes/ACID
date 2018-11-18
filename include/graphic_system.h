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
        drawable_objects = camera->get_scope();
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
