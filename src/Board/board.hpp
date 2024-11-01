#pragma once

#include <vector>
#include "member.hpp"
#include <iostream>

namespace board_ns {

    class Board {
    private:
        //std::vector<std::vector<member_ns::Piece*>> board;

    public:
        std::vector<std::vector<member_ns::Piece*>> board;
        Board();
        ~Board();
        void setBoard();  // Sets up the board to the initial configuration
        template <typename PieceType>
        bool isMoveValid(PieceType* piece, int fromX, int fromY, int toX, int toY, member_ns::Color currentPlayerColor) {
            if (!piece) {
                std::cout << "No piece at the starting position" << std::endl;
                return false;   
            }

            if (piece->getColor() != currentPlayerColor) {
                std::cout << "You can only move your own pieces" << std::endl;
                return false;
            }

            // check color and piece who has already there
            member_ns::Piece* targetPiece = getPiece(toX, toY);
            if (targetPiece && targetPiece->getColor() == currentPlayerColor) {
                std::cout << "Cannot move to a square occupied by your own piece" << std::endl;
                return false;
            }
            if (!piece->move(fromX, fromY, toX, toY)) {
                std::cout << "Invalid move for the piece" << std::endl;
                return false;
            }            
            // piece move rule
            //board[toX][toY] = piece;
            //board[fromX][fromY] = nullptr;
            std::cout << "Moved piece from (" << fromX << ", " << fromY << ") to (" << toX << ", " << toY << ")" << std::endl;
            return true;
            //return piece->move(fromX, fromY, toX, toY);
        }

        member_ns::Piece* getPiece(int x, int y) const;
        void printBoard() const;  // Prints the board
    };
}
