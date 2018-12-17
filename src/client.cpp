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
#include <fireball_creation_node.h>
#include <fireball_creation_system.h>
#include <client_shot_sychronization_system.h>
#include <single_world.h>
#include <collision_listener.h>
#include <X11/Xlib.h>
#include <network_systems/client_death_sync_system.h>


int main() {
    XInitThreads();  // <-- Need this to use multithreading along with graphics

    // creating map
    tmx_level level;
    try {
        level.LoadFromFile("../res/map.tmx");
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    auto* world = SingleWorld::get_instance();
    world->SetContactListener(new CollisionListener());
    // AFTER MAP LOADING!..
    // Creating window
    sf::RenderWindow window(sf::VideoMode(700, 700), "ACID");
    window.setFramerateLimit(60);
    window.setFramerateLimit(60);

    NetworkManager net;
    net.connect("localhost", 55503);



    Loop loop(&window, false);

    // Network systems
    auto spawn_system = new NetworkSpawnSystem(&net);
    auto net_receive = new NetworkReceiveSystem(&net);
    auto net_receive_move = new NetworkReceiveMoveSystem(&net);
    auto net_send = new NetworkSendSystem(&net);
    auto net_send_move_system = new NetworkSendMoveSystem(&net);
    auto client_death_sync = new ClientDeathSyncSystem(&net, loop.get_entity_manager());
    // Client systems
    auto* camera = new CameraSystem;
    auto* map = new MapSystem(&window, level);
    auto* graph_system = new GraphicSystem(&window, camera);
    auto* window_event_system = new WindowEventSystem(&window);
    auto* displayer_system = new DisplayerSystem(&window);
    auto* physic_system = new PhysicalSystem(world, level);
    auto* input_move_system = new InputMoveSystem;
    auto* move_system = new MoveSystem;
    auto* input_mouse_system = new InputMouseSystem(&window);
    auto* cl_shot = new ClientShotReceiveSystem(&net);
    auto* cl_shot_send = new ClientShotSendSystem(&net);
    // Nodes
    auto* input_mouse_node = new InputMouseNode;
    auto* move_node = new MoveNode;
    auto* input_move_node = new InputMoveNode;
    auto* graphic_node = new GraphicNode;
    auto* camera_node = new CameraNode;
    auto* player_pos_sync = new PlayerPosSyncNode;
    auto* client_pos_sync = new ClientPosSyncNode;
    auto* fireball_node = new FireballCreationNode;
    auto* mouse_node = new InputMouseNode;

    // Nodes registration
    loop.add_prototype(camera_node);
    loop.add_prototype(input_move_node);
    loop.add_prototype(graphic_node);
    loop.add_prototype(move_node);
    loop.add_prototype(input_mouse_node);
    loop.add_prototype(client_pos_sync);
    loop.add_prototype(player_pos_sync);
    loop.add_prototype(fireball_node);
    loop.add_prototype(mouse_node);
    // Systems registration
    loop.register_term_system(window_event_system);
    loop.register_life_system(spawn_system);
    loop.register_life_system(cl_shot);

    loop.add_system(net_receive);
    loop.add_system(spawn_system);
    loop.add_system(net_receive_move);
    loop.add_system(cl_shot);
    loop.add_system(physic_system);
    loop.add_system(camera);
    loop.add_system(window_event_system);
    loop.add_system(displayer_system);
    loop.add_system(map);
    loop.add_system(graph_system);
    loop.add_system(move_system);
    loop.add_system(input_move_system);
    loop.add_system(input_mouse_system);
    loop.add_system(client_death_sync);

    loop.add_system(cl_shot_send);
    loop.add_system(net_send_move_system);
    loop.add_system(net_send);

    loop.register_term_system(window_event_system);
    loop.run();

    /*XInitThreads();
    tmx_level level;
    try {
        level.LoadFromFile("../res/map.tmx");
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    NetworkManager net;
    sf::RenderWindow window(sf::VideoMode(700, 700), "ACID");
    Loop loop(&window);
    window.setFramerateLimit(60);
    auto* world = SingleWorld::get_instance();
    net.connect("localhost", 55503);
    //loop.add_prototype(new PlayerNode());

    auto spawn_system = new NetworkSpawnSystem(&net);
    //Система для выполнения приема данных. Добавляется ПЕРВОЙ
    auto net_receive = new NetworkReceiveSystem(&net);
    //Система(пример) для синхронизации перемещения по сети
    auto  net_move = new NetworkReceiveMoveSystem(&net);
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
    auto* move_system = new MoveSystem;
    auto* input_mouse_system = new InputMouseSystem(&window);
    // Create PhysicSystem
    auto* physic_system = new PhysicalSystem(world, level);


    auto* input_mouse_node = new InputMouseNode;


    // Creating InputMoveNode
    auto* input_move_node = new InputMoveNode;


    // Creating GraphicNode
    auto* graphic_node = new ClientGraphicNode;

    // Creating CameraNode
    auto* camera_node = new ClientCameraNode;
    loop.add_prototype(camera_node);
    loop.add_prototype(graphic_node);
    loop.add_prototype(input_move_node);
    loop.add_prototype(input_mouse_node);
    loop.register_term_system(window_event_system);
    loop.register_life_system(spawn_system);

    loop.add_system(net_receive);
    loop.add_system(camera);
    loop.add_system(window_event_system);
    loop.add_system(displayer_system);
    loop.add_system(map);
    loop.add_system(physic_system);
    loop.add_system(graph_system);
    loop.add_system(input_move_system);
    loop.add_system(input_mouse_system);
    loop.add_system(move_system);
    loop.add_system(net_move);
    loop.add_system(spawn_system);
    loop.add_system(net_send);

    loop.run();

    return 0;*/
}