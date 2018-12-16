#include <SFML/Graphics.hpp>

#include <custom_loop.h>
#include <window_event_system.h>
#include <single_world.h>
#include <input_mouse_component.h>
#include <input_mouse_node.h>
#include <input_mouse_system.h>
#include <fireball_creation_node.h>
#include <fireball_creation_system.h>
#include <client_graphic_system.h>
#include <damage_system.h>
#include <collision_component.h>
#include <health_component.h>
#include <collision_listener.h>
#include <entity_death_system.h>
#include <entity_death_node.h>
#include <death_component.h>
#include <projectile_lifetime_node.h>
#include <projectile_lifetime_system.h>

#include <X11/Xlib.h>
#include <mana/mana_component.h>
#include <skills/input_skill_component.h>
#include <mana/mana_node.h>
#include <skills/input_skill_node.h>
#include <skills/skill_node.h>
#include <mana/mana_regen_system.h>
#include <skills/input_skill_system.h>
#include <skills/fireball_burst_system.h>

class NONE {};

class GenSystem : public ActiveSystem<NONE>, public EntityLifeSystem {
  public:
    GenSystem(b2World* world): world(world) {}
    void execute() override {
        static size_t i = 0;
        Entity* entity = nullptr;
        Entity* entity1 = nullptr;
        if (i < 1) {
            i++;

            entity = new Entity();
            entity1 = new Entity();


            // Creating drawable object
            sf::Texture texture;
            if (!texture.loadFromFile("../textures/texture.jpg", sf::IntRect(0, 0, 32, 32))) {
                throw std::bad_typeid();
            }

            auto* player_sprite = new sf::Sprite;
            player_sprite->setTexture(texture);
            player_sprite->setOrigin(16.0f, 16.0f);
            auto* not_player_sprite = new sf::Sprite;
            *not_player_sprite = *player_sprite;

            b2BodyDef bodyDef1;
            b2BodyDef bodyDef2;

            bodyDef1.type = b2_dynamicBody;
            bodyDef2.type = b2_dynamicBody;

            bodyDef1.fixedRotation = true;
            bodyDef2.fixedRotation = true;
            bodyDef1.position.Set(10.0f, 10.0f);
            bodyDef2.position.Set(100.0f, 100.0f);

            b2Body* body1 = world->CreateBody(&bodyDef1);
            b2Body* body2 = world->CreateBody(&bodyDef2);

            b2PolygonShape shape1;
            b2PolygonShape shape2;

            shape1.SetAsBox(16.0f, 16.0f);
            shape2.SetAsBox(16.0f, 16.0f);

            body1->CreateFixture(&shape1,1.0f);
            body2->CreateFixture(&shape2,1.0f);
            // Creating graph components
            auto* player_texture_component1 = new TextureComponent(player_sprite);
            auto* player_collision_component1 = new CollisionComponent(body1);
            body1->SetUserData(player_collision_component1);
            auto* camera_component = new CameraComponent;
            auto* input_move_component = new InputMoveComponent;
            auto* input_mouse_component = new InputMouseComponent;
            auto health_component1 = new HealthComponent(100, 100);
            auto body_component1 = new BodyComponent(body1);
            auto death_component1 = new DeathComponent;
            auto mana_component = new ManaComponent(10, 10);
            auto input_skill_component = new InputSkillComponent;

            auto* player_texture_component2 = new TextureComponent(not_player_sprite);
            auto* player_collision_component2 = new CollisionComponent(body2);
            body2->SetUserData(player_collision_component2);
            auto health_component2 = new HealthComponent(11, 11);
            auto body_component2 = new BodyComponent(body2);
            auto death_component2 = new DeathComponent;

            entity->add_component(player_texture_component1);
            entity->add_component(player_collision_component1);
            entity->add_component(camera_component);
            entity->add_component(input_move_component);
            entity->add_component(input_mouse_component);
            entity->add_component(health_component1);
            entity->add_component(body_component1);
            entity->add_component(death_component1);
            entity->add_component(mana_component);
            entity->add_component(input_skill_component);

            entity1->add_component(player_collision_component2);
            entity1->add_component(player_texture_component2);
            entity1->add_component(health_component2);
            entity1->add_component(body_component2);
            entity1->add_component(death_component2);

            create_entity(entity);
            create_entity(entity1);
        }
    }

    b2World* world;
};

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
    // AFTER MAP LOADING!..
    // Creating window
    sf::RenderWindow window(sf::VideoMode(700, 700), "ACID");
    window.setFramerateLimit(60);

    // Create b2World
    auto* world = SingleWorld::get_instance();
    world->SetContactListener(new CollisionListener());

    Loop gameloop(&window, false);

    auto* camera = new CameraSystem;
    auto* map = new MapSystem(&window, level);
    auto* graph_system = new GraphicSystem(&window, camera);
    auto damage_system = new DamageSystem(gameloop.get_entity_manager());
    auto* window_event_system = new WindowEventSystem(&window);
    auto* displayer_system = new DisplayerSystem(&window);
    auto* physic_system = new PhysicalSystem(world, level);
    auto* gen_system = new GenSystem(world);
    auto* input_move_system = new InputMoveSystem;
    auto* move_system = new MoveSystem;
    auto entity_death_system = new EntityDeathSystem;
    auto* input_mouse_system = new InputMouseSystem(&window);
    auto* fireball_creation_system = new FireballCreationSystem;
    auto projectile_lifetime_system = new ProjectileLifetimeSystem;
    auto mana_regen_system = new ManaRegenSystem;
    auto input_skill_system = new InputSkillSystem;
    auto fireball_burst_system = new FireballBurstSystem;

    auto* fireball_creation_node = new FireballCreationNode;
    gameloop.add_prototype(fireball_creation_node);

    auto projectile_lifetime_node = new ProjectileLifetimeNode;
    gameloop.add_prototype(projectile_lifetime_node);

    auto* input_mouse_node = new InputMouseNode;
    gameloop.add_prototype(input_mouse_node);

    auto* move_node = new MoveNode;
    gameloop.add_prototype(move_node);

    auto* input_move_node = new InputMoveNode;
    gameloop.add_prototype(input_move_node);

    auto* graphic_node = new GraphicNode;
    gameloop.add_prototype(graphic_node);

    auto* camera_node = new CameraNode;
    gameloop.add_prototype(camera_node);

    auto* damage_node = new DamageNode;
    gameloop.add_prototype(damage_node);

    auto entity_death_node = new EntityDeathNode;
    gameloop.add_prototype(entity_death_node);

    auto mana_node = new ManaNode;
    gameloop.add_prototype(mana_node);

    auto input_skill_node = new InputSkillNode;
    gameloop.add_prototype(input_skill_node);

    auto skill_node = new SkillNode;
    gameloop.add_prototype(skill_node);

    gameloop.add_system(physic_system);
    gameloop.add_system(camera);
    gameloop.add_system(window_event_system);
    gameloop.add_system(displayer_system);
    gameloop.add_system(map);
    gameloop.add_system(graph_system);
    gameloop.add_system(move_system);
    gameloop.add_system(input_move_system);
    gameloop.add_system(input_mouse_system);
    gameloop.add_system(fireball_creation_system);
    gameloop.add_system(damage_system);
    gameloop.add_system(projectile_lifetime_system);
    gameloop.add_system(entity_death_system);
    gameloop.add_system(mana_regen_system);
    gameloop.add_system(input_skill_system);
    gameloop.add_system(fireball_burst_system);

    gameloop.register_life_system(gen_system);
    gameloop.register_life_system(fireball_creation_system);
    gameloop.register_life_system(entity_death_system);
    gameloop.register_life_system(fireball_burst_system);
    gameloop.register_term_system(window_event_system);
    gameloop.add_system(gen_system);
    gameloop.run();

    return 0;
}