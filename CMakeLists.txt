cmake_minimum_required(VERSION 3.12)
project(A.C.I.D.)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake-modules")
add_subdirectory(lib/googletest)
include_directories (
        include
        include/framework/test
        include/framework
        include/framework/test
        include/network_systems
        include/systems
        include/nodes
        include/components
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

        include/graphic_node.h
        include/texture_component.h
        include/graphic_manager.h
        include/position_component.h
        include/graphic_system.h
        include/camera_system.h
        include/camera_node.h
        include/camera_component.h
        include/displayer_system.h
        include/input_move_system.h
        include/input_move_node.h
        include/input_move_component.h
        include/move_system.h
        include/move_node.h
        include/custom_loop.h
        include/tmx_level.h
        include/map_draw_system.h
        include/window_event_system.h
        include/death_component.h
        include/test_death_system.h
        include/test_death_node.h
        include/test_toggle_death_system.h
        include/network_id.h
        include/network_manager.h
        include/server_network_manager.h
        include/physical_node.h
        include/physical_system.h
        include/collision_component.h
        include/single_world.h
        include/health_component.h
        include/damage_component.h
        include/projectile.h
        include/ACID_math.h
        include/input_mouse_system.h
        include/input_mouse_node.h
        include/input_mouse_component.h
        include/fireball_creation_node.h
        include/fireball_creation_system.h
        include/main_player.h
        include/client_player.h
        include/server_pos_sync_node.h
        include/client_pos_sync_node.h
        include/name_component.h
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
)
set (APP ${SRCS} ${HDRS})
##############################

set (
        CLIENT

        include/network_systems/client_shot_sychronization_system.h
        include/graphic_node.h
        include/texture_component.h
        include/graphic_manager.h
        include/position_component.h
        include/graphic_system.h
        include/camera_system.h
        include/camera_node.h
        include/camera_component.h
        include/displayer_system.h
        include/input_move_system.h
        include/input_move_node.h
        include/input_move_component.h
        include/custom_loop.h
        include/tmx_level.h
        include/map_draw_system.h
        include/window_event_system.h
        include/network_manager.h
        include/ACID_math.h
        include/input_mouse_system.h
        include/input_mouse_node.h
        include/input_mouse_component.h
        include/client_camera_node.h
        include/client_camera_system.h
        include/client_graphic_node.h
        include/client_graphic_system.h

        src/network_manager.cpp
        src/tmx_level.cpp
        src/projectile.cpp
        src/ACID_math.cpp
        src/main_player.cpp
        src/client_player.cpp

        include/network_systems/client_network_spawn_system.h
        include/network_systems/client_network_move_system.h
        include/network_systems/sever_network_sr_systems.h
)


set (
        SERVER
        include/network_systems/server_shot_synchroniztion_system.h
        include/position_component.h
        include/input_move_system.h
        include/input_move_node.h
        include/input_move_component.h
        include/move_system.h
        include/move_node.h
        include/custom_loop.h
        include/tmx_level.h
        include/map_draw_system.h
        include/window_event_system.h
        include/death_component.h
        include/test_death_system.h
        include/test_death_node.h
        include/test_toggle_death_system.h
        include/network_id.h
        include/network_manager.h
        include/server_network_manager.h
        include/physical_node.h
        include/physical_system.h
        include/collision_component.h
        include/single_world.h
        include/health_component.h
        include/damage_component.h
        include/projectile.h
        include/ACID_math.h
        include/input_mouse_system.h
        include/input_mouse_node.h
        include/input_mouse_component.h
        include/fireball_creation_node.h
        include/fireball_creation_system.h
        include/network_systems/server_network_spawn_system.h

        include/server_player.h


        src/server_network_manager.cpp
        src/tmx_level.cpp
        src/projectile.cpp
        src/ACID_math.cpp
        src/server_player.cpp

)


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
add_executable(death_graph_test src/death_graph_test.cpp ${APP} ${FRAMEWORK} )

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
target_link_libraries(death_graph_test ${SFML_LIBRARIES} xml)
target_link_libraries(ACID ${SFML_LIBRARIES} xml)

target_link_libraries(framework_gtest gtest gtest_main gmock gmock_main pthread)

target_link_libraries(test_server ${SFML_LIBRARIES})
target_link_libraries(test_client ${SFML_LIBRARIES})

target_link_libraries(server ${SFML_LIBRARIES} xml Box2D)
target_link_libraries(client ${SFML_LIBRARIES} xml Box2D pthread X11 imgui)
