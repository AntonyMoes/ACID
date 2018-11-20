#include <SFML/Graphics.hpp>

#include <custom_loop.h>


class GenSystem : public ActiveSystem<None>, public EntityLifeSystem {
  public:
    void execute() const override {
        static size_t i = 0;
        Entity* entity = nullptr;
        if (i < 1) {
            i++;

            entity = new Entity();

            // Creating drawable object
            sf::Texture texture;
            if (!texture.loadFromFile("../textures/texture.jpg", sf::IntRect(0, 0, 32, 32))) {
                throw std::bad_typeid();
            }

//            texture.setSmooth(true);
//            texture.setRepeated(true);
            sf::Sprite* player_sprite = new sf::Sprite;
            player_sprite->setTexture(texture);

            sf::Vector2f player_coords(0.f, 0.f);

            // Creating graph components
            auto* player_texture_component = new TextureComponent(player_sprite);
            auto* player_pos_component = new PositionComponent;
            auto* camera_component = new CameraComponent;
            auto* input_move_component = new InputMoveComponent;


            player_pos_component->set_coords(player_coords);

            entity->add_component(player_texture_component);
            entity->add_component(player_pos_component);
            entity->add_component(camera_component);
            entity->add_component(input_move_component);

            create_entity(entity);
        }
    }
};

int main() {

    // Creating window
    sf::RenderWindow window(sf::VideoMode(700, 700), "ACID");
    window.setFramerateLimit(60);

    Loop gameloop(&window);
    //Creating camera
    CameraSystem camera;

    // Creating graph system
    GraphicSystem graph_system(&window, &camera);

    // Create displayer system
    DisplayerSystem displayer_system(&window);

    GenSystem gen_system;
    InputMoveSystem input_move_system;
    MoveSystem move_system;

    MoveNode move_node;
    gameloop.add_prototype(&move_node);

    // Creating InputMoveNode
    InputMoveNode input_move_node;
    gameloop.add_prototype(&input_move_node);

    // Creating GraphicNode
    GraphicNode graphic_node;
    gameloop.add_prototype(&graphic_node);

    // Creating CameraNode
    CameraNode camera_node;
    gameloop.add_prototype(&camera_node);

    gameloop.add_system(&camera);
    gameloop.add_system(&displayer_system);
    gameloop.add_system(&graph_system);
    gameloop.add_system(&move_system);
    gameloop.add_system(&input_move_system);

    gameloop.register_life_system(&gen_system);
    gameloop.add_system(&gen_system);


    gameloop.run();

    return 0;
}