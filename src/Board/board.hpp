#pragma once

#include <vector>
#include "member.hpp"
#include <iostream>

namespace board_ns {

    class Board {
    private:
        std::vector<std::vector<member_ns::Piece*>> board;

    public:
        Board();
        ~Board();
        void setBoard();  // Sets up the board to the initial configuration
        bool isMoveValid(member_ns::Piece* piecePtr, int fromX, int fromY, int toX, int toY, member_ns::Color currentPlayerColor);

        member_ns::Piece* getPiece(int x, int y) const;
        void setPiece(int x, int y, member_ns::Piece* piecePtr);
        void printBoard() const;  // Prints the board
    };
}
