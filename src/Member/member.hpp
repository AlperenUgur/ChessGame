#pragma once

namespace member_ns {

    // Enum to represent piece color
    enum class Color { WHITE, BLACK };

    // Enum to represent different types of chess pieces
    enum class PieceType {
        NONE,   // Empty square
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING
    };

    // Base class for all chess pieces
    class Piece 
    {
    private:
        Color color;
        PieceType type;
    
    public:
        Piece(Color color, PieceType type) : color(color), type(type) {}
        virtual ~Piece() = default;

        // Pure virtual function to check if a move is valid for the piece
        virtual bool move(int fromX, int fromY, int toX, int toY) = 0;

        // Function to get the piece symbol for display
        virtual char getSymbol() const = 0;

        // Getter for the color of the piece
        Color getColor() const { return color; }

        // Getter for the type of the piece
        PieceType getType() const { return type; }
    };
    // Derived class for the Pawn piece
    class Pawn : public Piece {
    public:
        Pawn(Color color) : Piece(color, PieceType::PAWN) {}

        // Override move function for Pawn
        bool move(int fromX, int fromY, int toX, int toY) override;

        // Symbol for Pawn
        char getSymbol() const override { return 'P'; }
    };

    // Derived class for the Rook piece
    class Rook : public Piece {
    public:
        Rook(Color color) : Piece(color, PieceType::ROOK) {}

        // Override move function for Rook
        bool move(int fromX, int fromY, int toX, int toY) override;

        // Symbol for Rook
        char getSymbol() const override { return 'R'; }
    };

    // Derived class for the Knight piece
    class Knight : public Piece {
    public:
        Knight(Color color) : Piece(color, PieceType::KNIGHT) {}

        // Override move function for Knight
        bool move(int fromX, int fromY, int toX, int toY) override;

        // Symbol for Knight
        char getSymbol() const override { return 'N'; }
    };

    // Derived class for the Bishop piece
    class Bishop : public Piece {
    public:
        Bishop(Color color) : Piece(color, PieceType::BISHOP) {}

        // Override move function for Bishop
        bool move(int fromX, int fromY, int toX, int toY) override;

        // Symbol for Bishop
        char getSymbol() const override { return 'B'; }
    };

    // Derived class for the Queen piece
    class Queen : public Piece {
    public:
        Queen(Color color) : Piece(color, PieceType::QUEEN) {}

        // Override move function for Queen
        bool move(int fromX, int fromY, int toX, int toY) override;

        // Symbol for Queen
        char getSymbol() const override { return 'Q'; }
    };

    // Derived class for the King piece
    class King : public Piece {
    public:
        King(Color color) : Piece(color, PieceType::KING) {}

        // Override move function for King
        bool move(int fromX, int fromY, int toX, int toY) override;

        // Symbol for King
        char getSymbol() const override { return 'K'; }
    };

} // namespace member_ns
