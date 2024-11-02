#pragma once
#include "board.hpp"
#include "linkedList.hpp"
#include <iostream>
using namespace std;
namespace game_ns {
    class Game {
    private:
        static Game* instance;
        
        bool isWhiteTurn;  // White player starts first
        board_ns::Board board;  // Chess board
        
        Game();  // Private constructor for Singleton
        void playTurn();  // Processes a move and switches the player's turn
    public:
        static Game* getInstance();  // Returns Singleton instance
        void play();  // Starts the game
    };
}
