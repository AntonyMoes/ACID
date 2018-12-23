#include <server_player.h>
#include <mana/mana_component.h>


ServerPlayer::ServerPlayer(uint16_t id, float x, float y, bool is_player): Entity(id) {
    b2BodyDef body_def;

    body_def.type = b2_dynamicBody;

    body_def.fixedRotation = true;
    body_def.position.Set(x, y);

    auto world = SingleWorld::get_instance();
    b2Body* body = world->CreateBody(&body_def);

    b2PolygonShape shape;

    shape.SetAsBox(sizes.x / 2, sizes.y / 2);

    body->CreateFixture(&shape, 1.0f);
    // Creating graph components
    auto* name_component = new NameComponent(is_player);
    name_component->set_network_id(id);
    auto* player_collision_component = new CollisionComponent(body);
    body->SetUserData(player_collision_component);
    auto* input_move_component = new InputMoveComponent;
    auto* input_mouse_component = new InputMouseComponent;
    auto* health_component = new HealthComponent(100, 100);
    auto* mana_component = new ManaComponent(100);
    mana_component->set_mana(10);
    auto death_component = new DeathComponent;
    auto exp_component = new ExpComponent(20, 10, 2.0f, 2.0f);

    add_component(player_collision_component);
    add_component(input_move_component);
    add_component(input_mouse_component);
    add_component(name_component);
    add_component(health_component);
    add_component(mana_component);
    add_component(death_component);
    add_component(exp_component);
}