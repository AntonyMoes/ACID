cmake_minimum_required(VERSION 3.12)
project(A.C.I.D.)

set(CMAKE_CXX_STANDARD 14)


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
        include/i_observable.h
        include/i_observer.h
        include/entity_manager.h
        include/node_manager.h
        include/i_singleton.h
        include/proxy_singleton_observer.h
)
set (
        FRAMEWORK_SRCS

        src/i_system.cpp
        src/i_singleton.cpp
        src/i_node.cpp
        src/proxy_singleton_observer.cpp
        src/entity.cpp
        src/i_observable.cpp
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
set (APP ${SRCS} ${HDRS})
##############################


add_executable(ACID ${APP} ${FRAMEWORK})