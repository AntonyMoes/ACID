#ifndef ACID_INCLUDE_CLIENT_GRAPHIC_SYSTEM_H_
#define ACID_INCLUDE_CLIENT_GRAPHIC_SYSTEM_H_


#include <active_system.h>
#include <client_camera_system.h>
#include <client_graphic_node.h>
#include <client_camera_node.h>
#include <client_camera_system.h>
#include <client_camera_node.h>

class ClientGraphicSystem: public ActiveSystem<ClientCameraNode> {
  public:
    ClientGraphicSystem(sf::RenderWindow* window, ClientCameraSystem* camera):
    window(window),
    camera(camera) {}

    void execute() override {
        if (active_nodes.empty()) {
            return;
        }
        auto cam_node = *active_nodes.begin();
        auto cam_coord_comp = cam_node->get_component<PositionComponent>();

        sf::Vector2f center = cam_coord_comp->get_coords();
        sf::Vector2u window_size = window->getSize();

        auto drawable_objects = camera->get_scope(center, window_size.x, window_size.y);  // TODO: use view's size, not window's

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
    ClientCameraSystem* camera;
};

#endif  // ACID_INCLUDE_CLIENT_GRAPHIC_SYSTEM_H_
