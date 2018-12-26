#include <map>
#include <unistd.h>

#include <SFML/Audio.hpp>

#include <i_component.h>
#include <node.h>
#include <entity_life_system.h>
#include <game_loop.h>
#include <active_system.h>

#include <network_manager.h>
#include <network_id.h>
#include <client_network_sr_systems.h>
#include <client_network_move_system.h>
#include <generators/client_network_spawn_system.h>
#include <graphic/client_graphic_system.h>
#include <graphic/tmx_level.h>
#include <single_world.h>
#include <graphic/map_draw_system.h>
#include <window_event_system.h>
#include <graphic/displayer_system.h>
#include <input_move_system.h>
#include <movements/client_move_system.h>
#include <input_mouse_system.h>
#include <movements/move_node.h>
#include <custom_loop.h>
#include <fireball_creation_node.h>
#include <fireball_creation_system.h>
#include <client_shot_sychronization_system.h>
#include <single_world.h>
#include <collision/collision_listener.h>
#include <death/client_death_sync_system.h>
#include <health/client_health_sync_system.h>
#include <healthbar.hpp>
#include <hp_node.hpp>
#include <graphic/texture_manager.h>
#include <client_exp_sync_system.h>
#include <client_exp_sync_node.h>
#include <client_expball_sync_system.h>
#include <SFML/Audio.hpp>

#include <X11/Xlib.h>   // Мust be included last
#include <mana/client_network_mana_system.h>
#include <skills/skill_sync_node.h>
#include <skills/input_skill_node.h>
#include <skills/client_network_skill_system.h>
#include <skills/input_skill_system.h>
#include <imgui/imgui-SFML.h>
#include <skills/skill_lvlup_system.h>
#include <skills/skill_lvlup_node.h>
#include <skills/lvl_to_point_node.h>
#include <skills/lvl_to_point_system.h>
#include <skills/client_network_lvlup_system.h>


std::pair<std::string, unsigned int> get_addr(sf::RenderWindow* window) {
    static bool ok = true;
    static bool was_ok = true;
    char ip[17] = "localhost";
    int port = 55503;
    sf::Clock delta_clock;
    sf::Event event;

    sf::SoundBuffer vuf;
    vuf.loadFromFile("../res/Despacito.ogg");

    sf::Sound despacito(vuf);
    despacito.play();
    despacito.setLoop(true);
    despacito.setVolume(10);

    while (was_ok) {
        was_ok = ok;
        while (window->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                //terminator = false;
                //thread->join();
                //delete thread;
                window->close();
                exit(1);
            }

            if (event.type == sf::Event::Resized) {
                auto view = window->getView();
                sf::Vector2u size = window->getSize();
                view.setSize(size.x, size.y);
                window->setView(view);
            }
        }


        ImGui::SFML::Update(*window, delta_clock.restart());
        ImGui::SetNextWindowPos({0, 0});
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
        ImGui::Begin("Hoba", &ok, ImGuiWindowFlags_NoCollapse || ImGuiWindowFlags_NoTitleBar);
        auto size = ImGui::GetIO().DisplaySize;
        auto height = size.y;
        auto width = size.x;
        for (size_t i = 0; i < height / 40; ++i) {
            ImGui::Text("\n");
        }
        for (size_t i = 0; i < width / 32; ++i) {
            ImGui::Text(" ");
            ImGui::SameLine();
        }
        ImGui::PushItemWidth(120);
        ImGui::InputText("IP", ip, 16);
        for (size_t i = 0; i < width / 32; ++i) {
            ImGui::Text(" ");
            ImGui::SameLine();
        }
        //if (ImGui::InputText("Port", windowTitle, 16)) {
        ImGui::InputInt("Port", &port, 16);

        for (size_t i = 0; i < width / 32; ++i) {
            ImGui::Text(" ");
            ImGui::SameLine();
        }
        if (ImGui::Button("     Connect     ")) {
            ok = false;
        }
        ImGui::PopItemWidth();
        ImGui::End();


        window->clear();
        ImGui::SFML::Render(*window);
        window->display();
    }

    window->clear();
    ImGui::SFML::Render(*window);
    window->display();

    despacito.stop();



    return std::make_pair(std::string(ip), abs(port));
}

int main() {
    XInitThreads();  // <-- Need this to use multithreading along with graphics

    std::string ip;
    unsigned int port = 0;

    sf::Music game_soundtrack;
    if (!game_soundtrack.openFromFile("../res/soundtrack.ogg")) {
        std::cerr << "Couldn`t find soundtrack file!" << std::endl;
        return 1;
    }
    game_soundtrack.setVolume(10.0f);
    game_soundtrack.setLoop(true);

    // creating map
    tmx_level level;
    try {
        level.LoadFromFile("../res/newmap.tmx");
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

    ImGui::SFML::Init(window);
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->Clear();
    io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF("../fonts/ProggyTiny.ttf", 16.f);
    ImGui::SFML::UpdateFontTexture();
    std::tie(ip, port) = get_addr(&window);

    NetworkManager net;

    net.connect(ip, port);

    TextureManager texture_manager;

    Loop loop(&window, false);

    // Network systems
    auto client_network_skill_system = new ClientNetworkSkillSystem(&net);
    auto input_skill_system = new InputSkillSystem;
    auto mana_sync_system = new ClientNetworkManaSystem(&net);
    auto spawn_system = new NetworkSpawnSystem(&net);
    auto net_receive = new NetworkReceiveSystem(&net);
    auto net_receive_move = new NetworkReceiveMoveSystem(&net);
    auto net_send = new NetworkSendSystem(&net);
    auto net_send_move_system = new NetworkSendMoveSystem(&net);
    auto client_death_sync = new ClientDeathSyncSystem(&net, loop.get_entity_manager());
    auto client_health_sync = new ClientHealthSyncSystem(&net);
    auto client_exp_sync = new ClientExpSyncSystem(&net);
    auto client_expball_sync = new ClientExpBallSyncSystem(&net);
    // Client systems
    auto* camera = new CameraSystem;
    auto* map = new MapSystem(&window, level);
    auto* graph_system = new GraphicSystem(&window, camera);
    auto* window_event_system = new WindowEventSystem(&window);
    auto* displayer_system = new DisplayerSystem(&window);
    auto* physic_system = new PhysicalSystem(world, level);
    auto* input_move_system = new InputMoveSystem;
    auto skill_lvlup_system = new SkillLvlupSystem(&window);
    auto lvl_to_point_system= new LvlToPointSystem;
    auto* move_system = new MoveSystem;
    auto* input_mouse_system = new InputMouseSystem(&window);
    auto* cl_shot = new ClientShotReceiveSystem(&net);
    auto* cl_shot_send = new ClientShotSendSystem(&net);
    auto healthbar_system = new Healthbar(&window, &texture_manager);
    // Nodes
    auto skill_sync_node = new SkillSyncNode;
    auto input_skill_node = new InputSkillNode;
    auto mana_sync_node = new ManaSyncNode;
    auto* input_mouse_node = new InputMouseNode;
    auto* move_node = new MoveNode;
    auto* input_move_node = new InputMoveNode;
    auto* graphic_node = new GraphicNode;
    auto* camera_node = new CameraNode;
    auto* player_pos_sync = new PlayerPosSyncNode;
    auto* client_pos_sync = new ClientPosSyncNode;
    auto* fireball_node = new FireballCreationNode;
    auto* mouse_node = new InputMouseNode;
    auto hp_node = new HPNode;
    auto health_sync_node = new ClientHealthSyncNode;
    auto exp_sync_node = new ClientExpSyncNode;

    // Nodes registration
    loop.add_prototype(input_skill_node);
    loop.add_prototype(skill_sync_node);
    loop.add_prototype(mana_sync_node);
    loop.add_prototype(camera_node);
    loop.add_prototype(input_move_node);
    loop.add_prototype(graphic_node);
    loop.add_prototype(move_node);
    loop.add_prototype(input_mouse_node);
    loop.add_prototype(client_pos_sync);
    loop.add_prototype(player_pos_sync);
    loop.add_prototype(fireball_node);
    loop.add_prototype(mouse_node);
    loop.add_prototype(hp_node);
    loop.add_prototype(new SkillLvlupNode);
    loop.add_prototype(new LvlToPointNode);
    loop.add_prototype(new LvlupSyncNode);
    loop.add_prototype(health_sync_node);
    loop.add_prototype(exp_sync_node);
    // Systems registration
    loop.register_term_system(window_event_system);
    loop.register_life_system(client_expball_sync);
    loop.register_life_system(spawn_system);
    loop.register_life_system(cl_shot);

    
    loop.add_system(net_receive);
    loop.add_system(spawn_system);
    loop.add_system(net_receive_move);
    loop.add_system(mana_sync_system);
    loop.add_system(input_skill_system);
    loop.add_system(client_network_skill_system);
    loop.add_system(cl_shot);
    loop.add_system(physic_system);
    loop.add_system(camera);
    loop.add_system(window_event_system);
    loop.add_system(displayer_system);
    loop.add_system(map);
    loop.add_system(new ClientNetworkLvlupSystem(&net));
    loop.add_system(graph_system);
    loop.add_system(move_system);
    loop.add_system(input_move_system);
    loop.add_system(skill_lvlup_system);
    loop.add_system(lvl_to_point_system);
    loop.add_system(input_mouse_system);
    loop.add_system(healthbar_system);
    loop.add_system(client_health_sync);
    loop.add_system(client_exp_sync);
    loop.add_system(client_expball_sync);
    loop.add_system(client_death_sync);

    loop.add_system(cl_shot_send);
    loop.add_system(net_send_move_system);
    loop.add_system(net_send);

    loop.register_term_system(window_event_system);

    game_soundtrack.play();
    loop.run();
    game_soundtrack.stop();
}