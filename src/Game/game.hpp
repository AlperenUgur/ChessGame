#pragma once
#include "board.hpp"
#include "linkedList.hpp"
#include <iostream>
using namespace std;
namespace game_ns {
    class Game {
    private:
        static Game* instance;
        board_ns::Board board;  // Chess board
        
        LinkedList<string> moveHistory;  // History of moves
        bool isWhiteTurn;  // White player starts first
        Game();  // Private constructor for Singleton
    public:
        static Game* getInstance();  // Returns Singleton instance
        void start();  // Starts the game
        void playTurn();  // Processes a move and switches the player's turn
    };
}
