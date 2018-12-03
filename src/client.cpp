#include <map>
#include <unistd.h>

#include <framework/i_component.h>
#include <node.h>
#include <entity_life_system.h>
#include <framework/game_loop.h>
#include <network_manager.h>
#include <active_system.h>
#include <network_id.h>
#include <network_systems/client_network_sr_systems.h>
#include <network_systems/client_network_move_system.h>
#include <network_systems/client_network_spawn_system.h>
#include <client_graphic_system.h>
#include <tmx_level.h>
#include <single_world.h>
#include <map_draw_system.h>
#include <window_event_system.h>
#include <displayer_system.h>
#include <input_move_system.h>
#include <client_move_system.h>
#include <input_mouse_system.h>
#include <move_node.h>
#include <custom_loop.h>

//TODO: Эта ситема отвечает за синхронизацию преремещения по сети, для нее нужна нода


int main() {
    NetworkManager net;
    sf::RenderWindow window(sf::VideoMode(700, 700), "ACID");
    Loop loop(&window);
    window.setFramerateLimit(60);
    tmx_level level;
    try {
        level.LoadFromFile("../res/map.tmx");
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    auto* world = SingleWorld::get_instance();
    net.connect("localhost", 55503);
    //loop.add_prototype(new PlayerNode());

    auto spawn_system = new NetworkSpawnSystem(&net);
    //Система для выполнения приема данных. Добавляется ПЕРВОЙ
    auto net_receive = new NetworkReceiveSystem(&net);
    //Система(пример) для синхронизации перемещения по сети
    auto  net_move = new NetworkMoveSystem(&net);
    //Система для отправки данных. Добавляется ПОСЛЕДНЕЙ
    auto net_send = new NetworkSendSystem(&net);





    auto* camera = new ClientCameraSystem;
    auto* map = new MapSystem(&window, level);
    // Creating graph system
    auto* graph_system = new ClientGraphicSystem(&window, camera);
    // Creating window event system
    auto* window_event_system = new WindowEventSystem(&window);

    // Create displayer system
    auto* displayer_system = new DisplayerSystem(&window);
    // Create InputMoveSystem
    auto* input_move_system = new InputMoveSystem;

    auto* input_mouse_system = new InputMouseSystem(&window);



    auto* input_mouse_node = new InputMouseNode;
    loop.add_prototype(input_mouse_node);

    // Creating InputMoveNode
    auto* input_move_node = new InputMoveNode;
    loop.add_prototype(input_move_node);

    // Creating GraphicNode
    auto* graphic_node = new ClientGraphicNode;
    loop.add_prototype(graphic_node);

    // Creating CameraNode
    auto* camera_node = new ClientCameraNode;
    loop.add_prototype(camera_node);

    loop.add_system(camera);
    loop.add_system(window_event_system);
    loop.add_system(displayer_system);
    loop.add_system(map);
    loop.add_system(graph_system);
    loop.add_system(input_move_system);
    loop.add_system(input_mouse_system);

    loop.register_term_system(window_event_system);



    loop.register_life_system(spawn_system);
    loop.add_system(net_receive);
    loop.add_system(net_move);
    loop.add_system(spawn_system);
    loop.add_system(net_send);

    loop.run();

    return 0;
}