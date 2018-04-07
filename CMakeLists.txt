cmake_minimum_required(VERSION 3.3)
project(potato-framework)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/potato ${CMAKE_CURRENT_SOURCE_DIR}/extlibs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network -fPIC")

set(SOURCE_FILES potato/application.cpp
        potato/application.hpp
        potato/controllers/playercontroller.cpp
        potato/controllers/playercontroller.hpp
        potato/datatables.cpp
        potato/datatables.hpp
        potato/entities/emitternode.cpp
        potato/entities/emitternode.hpp
        potato/entities/entity.cpp
        potato/entities/entity.hpp
        potato/entities/particlenode.cpp
        potato/entities/particlenode.hpp
        potato/entities/quadtree.cpp
        potato/entities/quadtree.hpp
        potato/entities/scenenode.cpp
        potato/entities/scenenode.hpp
        potato/entities/soundnode.cpp
        potato/entities/soundnode.hpp
        potato/entities/spritenode.cpp
        potato/entities/spritenode.hpp
        potato/entities/textnode.cpp
        potato/entities/textnode.hpp
        potato/events/category.hpp
        potato/events/command.cpp
        potato/events/command.hpp
        potato/events/commandqueue.cpp
        potato/events/commandqueue.hpp
        potato/GUI/button.cpp
        potato/GUI/button.hpp
        potato/GUI/container.cpp
        potato/GUI/container.hpp
        potato/GUI/label.cpp
        potato/GUI/label.hpp
        potato/GUI/lineedit.cpp
        potato/GUI/lineedit.hpp
        potato/GUI/widget.cpp
        potato/GUI/widget.hpp
        potato/resources/affectors.cpp
        potato/resources/affectors.hpp
        potato/resources/animation.cpp
        potato/resources/animation.hpp
        potato/resources/musicplayer.cpp
        potato/resources/musicplayer.hpp
        potato/resources/particle.cpp
        potato/resources/particle.hpp
        potato/resources/resourceholder.hpp
        potato/resources/resourceidentifiers.hpp
        potato/resources/scriptplayer.cpp
        potato/resources/scriptplayer.hpp
        potato/resources/soundplayer.cpp
        potato/resources/soundplayer.hpp
        potato/states/paralleltask.cpp
        potato/states/paralleltask.hpp
        potato/states/state.cpp
        potato/states/state.hpp
        potato/states/stateidentifiers.hpp
        potato/states/statestack.cpp
        potato/states/statestack.hpp
        potato/states/titlestate.cpp
        potato/states/titlestate.hpp
        potato/utils.cpp
        potato/utils.hpp
        potato/utils.inl
        potato/world.cpp
        potato/world.hpp
        potato/utils/nlohmann/json.hpp
        potato/utils/json.hpp)
set(TEST_SOURCE_FILES tests/tests.cpp tests/utils/json.cpp)

# Building libpotato-framework
add_library(potato-framework SHARED ${SOURCE_FILES})
install(TARGETS potato-framework DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build)
target_link_libraries(potato-framework dl pthread)

# Building tests
add_executable(unittests ${SOURCE_FILES} ${TEST_SOURCE_FILES})
target_link_libraries(unittests dl pthread sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
