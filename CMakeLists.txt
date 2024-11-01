# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(ChessGame)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for headers
include_directories(
    src/Board
    src/Game
    src/Member
    src/lib  
)

# Add the executable and specify all source files
add_executable(chess
    src/Main/main.cpp
    src/Board/board.cpp
    src/Game/game.cpp
    src/Member/member.cpp
)