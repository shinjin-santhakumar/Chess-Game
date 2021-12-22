cmake_minimum_required(VERSION 3.15)
project(ProjectTest1)

include_directories( ./src )
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        main.cpp
        src/GameManager.cpp
        src/Board.cpp
        src/Pawn.cpp
        src/King.cpp
        src/Rook.cpp
        src/Knight.cpp
        src/Queen.cpp
        src/Bishop.cpp
        )

add_executable(my_exec ${SOURCE_FILES})