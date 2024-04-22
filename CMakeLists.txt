cmake_minimum_required(VERSION 3.5)

project(RPG-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)

add_executable(RPG-game main.cpp
    hero.h
    enemy.h
    datamanager.h)

target_link_libraries(RPG-game Qt5::Core Qt5::Quick Qt5::Sql)



include(GNUInstallDirs)
install(TARGETS RPG-game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
