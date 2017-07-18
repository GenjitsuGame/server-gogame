cmake_minimum_required(VERSION 3.6)
project(server_gg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES server.cpp chat_message.hpp)
add_executable(server_gg ${SOURCE_FILES})

find_package(Boost COMPONENTS system REQUIRED)


target_link_libraries(
        server_gg
        ${Boost_LIBRARIES}
)