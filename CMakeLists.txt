cmake_minimum_required(VERSION 3.12)
project(A.C.I.D.)

set(CMAKE_CXX_STANDARD 17)


include_directories (
        include
        include/test
        include/framework
        include/framework/test
)
add_subdirectory(lib/googletest)
include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)
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
)
set (
        FRAMEWORK_SRCS

        src/framework/i_system.cpp
        src/framework/i_singleton.cpp
        src/framework/i_node.cpp
        src/framework/node.cpp
        src/framework/proxy_singleton_observer.cpp
        src/framework/entity.cpp
        src/framework/i_observable.cpp
        src/framework/entity_manager.cpp
        src/framework/node_manager.cpp
        src/framework/i_component.cpp
        src/framework/active_system.cpp
        src/framework/reactive_system.cpp
        src/framework/game_loop.cpp
        src/framework/base_system.cpp
        src/framework/entity_life_queue.cpp
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
add_executable(framework_test_example src/framework_test_example.cpp ${FRAMEWORK})
add_executable(framework_gtest test/test.cpp ${FRAMEWORK} test/test_icomponent.cpp)

target_link_libraries(framework_gtest gtest gtest_main gmock gmock_main pthread)