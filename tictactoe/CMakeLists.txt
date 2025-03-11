cmake_minimum_required(VERSION 3.20)
project(TicTacToe)

set(SOURCE_FILES
    main.cpp
    GameBoard.cpp
    GameBoard.h
    Opponent.h
    BasicOpponent.h
    BasicOpponent.cpp
)

add_executable(tic_tac_toe ${SOURCE_FILES})