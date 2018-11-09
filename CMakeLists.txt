cmake_minimum_required(VERSION 3.12)
project(A.C.I.D.)

set(CMAKE_CXX_STANDARD 17)


include_directories (
        include
        include/test
)

##############################
set (
        FRAMEWORK_HDRS

        include/i_system.h
        include/active_system.h
        include/reactive_system.h
        include/game_loop.h
        include/entity.h
        include/entity_life_queue.h
        include/i_component.h
        include/i_node.h
        include/node.h
        include/i_observable.h
        include/i_observer.h
        include/entity_manager.h
        include/node_manager.h
        include/i_singleton.h
        include/proxy_singleton_observer.h
        include/base_system.h
)
set (
        FRAMEWORK_SRCS

        src/i_system.cpp
        src/i_singleton.cpp
        src/i_node.cpp
        src/node.cpp
        src/proxy_singleton_observer.cpp
        src/entity.cpp
        src/i_observable.cpp
        src/entity_manager.cpp
        src/node_manager.cpp
        src/i_component.cpp
        src/active_system.cpp
        src/reactive_system.cpp
        src/game_loop.cpp
        src/base_system.cpp
        src/entity_life_queue.cpp
)
set (FRAMEWORK ${FRAMEWORK_HDRS} ${FRAMEWORK_SRCS})
##############################


##############################
set (
        HDRS
)
set (
        SRCS

        src/main.cpp
)
set (APP ${SRCS} ${HDRS} src/hasher.cpp)
##############################


add_executable(ACID ${APP} ${FRAMEWORK})
add_executable(framework_test_example src/framework_test_example.cpp ${FRAMEWORK})