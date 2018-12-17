cmake_minimum_required(VERSION 3.12)
project(A.C.I.D.)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake-modules")

add_subdirectory(lib/googletest)
include_directories (
        include
        include/framework
        include/framework/test
        include/network_systems
        include/systems
        include/nodes
        include/components
        include/entities
        include/mana
        include/skills
        include/damage
        include/camera
        include/graphic
        include/movements
        include/death
        include/input
        include/generators
        include/position
        include/collision
        include/health
        include/physic
        include/exp
        include/projectile
        include/network
)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR} )

##############################
set (
        FRAMEWORK_HDRS

        include/framework/i_system.h
        include/framework/active_system.h
        include/framework/reactive_system.h
        include/framework/game_loop.h
        include/framework/entity.h
        include/framework/entity_life_queue.h
        include/framework/i_component.h
        include/framework/i_node.h
        include/framework/node.h
        include/framework/i_observable.h
        include/framework/i_observer.h
        include/framework/entity_manager.h
        include/framework/node_manager.h
        include/framework/i_singleton.h
        include/framework/proxy_singleton_observer.h
        include/framework/base_system.h
        include/framework/entity_life_system.h
        include/framework/terminator_system.h
)

set (
        TEST_FRAMEWORK_HDRS

        include/framework/test/test_node.h
        include/framework/test/test_icomponent.h
        include/framework/test/test_node_manager.h
        include/framework/test/test_entity.h
        #include/framework/test/test_activesystems_cycle.h
        include/framework/test/test_reactivesystems_cycle.h
)

set (
        FRAMEWORK_SRCS

        src/framework/i_node.cpp
        src/framework/entity.cpp
        src/framework/entity_manager.cpp
        src/framework/node_manager.cpp
        src/framework/i_component.cpp
        src/framework/game_loop.cpp
        src/framework/entity_life_queue.cpp
)

set (
        TEST_FRAMEWORK_SRC

        src/framework/test/test_node.cpp
        src/framework/test/test_icomponent.cpp
        src/framework/test/test_node_manager.cpp
        src/framework/test/test_entity.cpp
        #src/framework/test/test_activesystems_cycle.cpp
        src/framework/test/test_reactivesystems_cycle.cpp
)

set (FRAMEWORK ${FRAMEWORK_HDRS} ${FRAMEWORK_SRCS})

set (TEST_FRAMEWORK ${TEST_FRAMEWORK_HDRS} ${TEST_FRAMEWORK_SRC})
##############################


##############################
set (
        HDRS

        include/graphic/graphic_node.h
        include/graphic/texture_component.h
        include/graphic/graphic_manager.h
        include/position/position_component.h
        include/graphic/graphic_system.h
        include/camera/camera_system.h
        include/camera/camera_node.h
        include/camera/camera_component.h
        include/graphic/displayer_system.h
        include/input/input_move_system.h
        include/input/input_move_node.h
        include/input/input_move_component.h
        include/movements/move_system.h
        include/movements/move_node.h
        include/custom_loop.h
        include/graphic/tmx_level.h
        include/graphic/map_draw_system.h
        include/window_event_system.h
        include/network/network_id.h
        include/network/network_manager.h
        include/network/server_network_manager.h
        include/physic/physical_node.h
        include/physic/physical_system.h
        include/collision/collision_component.h
        include/single_world.h
        include/health/health_component.h
        include/damage/damage_component.h
        include/entities/projectile.h
        include/ACID_math.h
        include/input/input_mouse_system.h
        include/input/input_mouse_node.h
        include/input/input_mouse_component.h
        include/generators/fireball_creation_node.h
        include/generators/fireball_creation_system.h
        include/entities/main_player.h
        include/entities/client_player.h
        include/position/server_pos_sync_node.h
        include/position/client_pos_sync_node.h
        include/entities/name_component.h
        include/entities/body_component.h
        include/death/death_component.h
        include/projectile/lifetime_component.h
        include/projectile/projectile_lifetime_node.h
        include/projectile/projectile_lifetime_system.h

        include/mana/mana_component.h
        include/mana/mana_node.h
        include/mana/mana_regen_system.h
        include/skills/fireball_burst_system.h
        include/skills/input_skill_component.h
        include/skills/input_skill_node.h
        include/skills/input_skill_system.h
        include/skills/skill_node.h

        include/exp/exp_component.h
        include/exp/exp_distribution_system.h
        include/exp/exp_distribution_node.h
        include/entities/exp_ball.h
        include/exp/drop_exp_component.h
        include/generators/exp_creation_system.h
        include/generators/exp_creation_node.h

        include/graphic/texture_manager.h
)
set (
        SRCS

        src/network_manager.cpp
        src/server_network_manager.cpp
        src/tmx_level.cpp
        src/projectile.cpp
        src/ACID_math.cpp
        src/main_player.cpp
        src/client_player.cpp
        src/server_player.cpp
        src/texture_manager.cpp
        src/exp_ball.cpp
)
set (APP ${SRCS} ${HDRS})
##############################

set (
        CLIENT_HDRS

        include/input/client_shot_sychronization_system.h
        include/graphic/graphic_node.h
        include/graphic/texture_component.h
        include/graphic/graphic_manager.h
        include/position/position_component.h
        include/graphic/graphic_system.h
        include/camera/camera_system.h
        include/camera/camera_node.h
        include/camera/camera_component.h
        include/graphic/displayer_system.h
        include/input/input_move_system.h
        include/input/input_move_node.h
        include/input/input_move_component.h
        include/custom_loop.h
        include/graphic/tmx_level.h
        include/graphic/map_draw_system.h
        include/window_event_system.h
        include/network/network_manager.h
        include/ACID_math.h
        include/input/input_mouse_system.h
        include/input/input_mouse_node.h
        include/input/input_mouse_component.h
        include/camera/client_camera_node.h
        include/camera/client_camera_system.h
        include/graphic/client_graphic_node.h
        include/graphic/client_graphic_system.h
        include/graphic/texture_manager.h
        include/graphic/animation_component.h
        include/health/health_component.h
        include/damage/damage_component.h
        include/entities/body_component.h
        include/death/death_component.h
        include/projectile/lifetime_component.h
        include/projectile/projectile_lifetime_node.h
        include/projectile/projectile_lifetime_system.h
        include/mana/mana_component.h
        include/mana/mana_node.h
        include/death/client_death_sync_system.h

        include/generators/client_network_spawn_system.h
        include/movements/client_network_move_system.h
        include/network/sever_network_sr_systems.h
        include/health/client_health_sync_node.h
        include/health/client_health_sync_system.h
        include/mana/mana_component.h
        include/mana/mana_node.h
        include/mana/mana_regen_system.h
        include/health/healthbar.hpp
        include/health/hp_node.hpp
        include/exp/client_exp_sync_node.h
        include/exp/client_exp_sync_system.h
)

set (
        CLIENT_SRCS

        src/texture_manager.cpp
        src/client_player.cpp
        src/tmx_level.cpp
        src/projectile.cpp
        src/ACID_math.cpp
        src/main_player.cpp
        src/network_manager.cpp
)

set (CLIENT ${CLIENT_HDRS} ${CLIENT_SRCS})

set (
        SERVER_HDRS

        include/input/server_shot_synchroniztion_system.h
        include/position/position_component.h
        include/input/input_move_system.h
        include/input/input_move_node.h
        include/input/input_move_component.h
        include/movements/move_system.h
        include/movements/move_node.h
        include/custom_loop.h
        include/graphic/tmx_level.h
        include/graphic/map_draw_system.h
        include/window_event_system.h
        include/network/network_id.h
        include/network/network_manager.h
        include/network/server_network_manager.h
        include/physic/physical_node.h
        include/physic/physical_system.h
        include/collision/collision_component.h
        include/single_world.h
        include/health/health_component.h
        include/damage/damage_component.h
        include/entities/projectile.h
        include/ACID_math.h
        include/input/input_mouse_system.h
        include/input/input_mouse_node.h
        include/input/input_mouse_component.h
        include/generators/fireball_creation_node.h
        include/generators/fireball_creation_system.h
        include/generators/server_network_spawn_system.h
        include/death/entity_death_node.h
        include/death/entity_death_system.h
        include/collision/collision_listener.h
        include/damage/damage_system.h
        include/damage/damage_node.h
        include/health/health_component.h
        include/damage/damage_component.h
        include/entities/body_component.h
        include/death/death_component.h
        include/projectile/lifetime_component.h
        include/projectile/projectile_lifetime_node.h
        include/projectile/projectile_lifetime_system.h
        include/entities/server_player.h
        include/mana/mana_component.h
        include/mana/mana_node.h
        include/mana/mana_regen_system.h
        include/skills/fireball_burst_system.h
        include/skills/input_skill_component.h
        include/skills/input_skill_node.h
        include/skills/input_skill_system.h
        include/skills/skill_node.h
        include/death/server_death_synchroniztion_system.h
        include/health/server_health_sync_node.h
        include/health/server_health_sync_system.h
        include/exp/server_exp_sync_node.h
        include/exp/server_exp_sync_system.h
)

set (
        SERVER_SRCS

        src/server_network_manager.cpp
        src/tmx_level.cpp
        src/projectile.cpp
        src/ACID_math.cpp
        src/server_player.cpp
        src/exp_ball.cpp
)

set (SERVER ${SERVER_HDRS} ${SERVER_SRCS})


set(
        IMGUI

        lib/imgui/imconfig.h
        lib/imgui/imgui.h
        lib/imgui/imgui.cpp
        lib/imgui/imgui_internal.h
        lib/imgui/imstb_rectpack.h
        lib/imgui/imstb_textedit.h
        lib/imgui/imstb_truetype.h
        lib/imgui/imgui_draw.cpp
        lib/imgui/imgui_widgets.cpp
)


add_library(xml lib/tinyxml2/tinyxml2.cpp lib/tinyxml2/tinyxml2.h)
add_library(imgui ${IMGUI})
add_executable(ACID src/main.cpp ${APP} ${FRAMEWORK})
add_executable(framework_test_example src/framework_test_example.cpp ${FRAMEWORK})
add_executable(framework_gtest src/framework/test/test.cpp ${FRAMEWORK} ${TEST_FRAMEWORK})

add_executable(Singleplayer src/singleplayer.cpp ${APP} ${FRAMEWORK} )

add_executable(test_client src/test_client.cpp ${APP} ${FRAMEWORK})
add_executable(test_server src/test_server.cpp ${APP} ${FRAMEWORK})


add_executable(client src/client.cpp ${CLIENT} ${FRAMEWORK})
add_executable(server src/server.cpp ${SERVER} ${FRAMEWORK})


SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(SFML 2 COMPONENTS graphics audio network window system REQUIRED)
find_package(Box2D REQUIRED)
find_package(X11 REQUIRED)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
target_link_libraries(framework_gtest gtest gtest_main pthread)
target_link_libraries(ACID ${SFML_LIBRARIES})
target_link_libraries(Singleplayer ${SFML_LIBRARIES} xml Box2D pthread X11 imgui)
target_link_libraries(ACID ${SFML_LIBRARIES} xml)

target_link_libraries(framework_gtest gtest gtest_main gmock gmock_main pthread)

target_link_libraries(test_server ${SFML_LIBRARIES})
target_link_libraries(test_client ${SFML_LIBRARIES})

target_link_libraries(server ${SFML_LIBRARIES} xml Box2D)
target_link_libraries(client ${SFML_LIBRARIES} xml Box2D pthread X11 imgui)