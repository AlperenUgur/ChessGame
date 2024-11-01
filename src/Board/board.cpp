#include "board.hpp"
#include "member.hpp"
using namespace std;
namespace board_ns

{

Board::Board()
	: board(8, std::vector<member_ns::Piece*>(8, nullptr))
{ }

Board::~Board()
{
	for(auto& row : board)
	{
		for(auto& piece : row)
		{
			delete piece;
		}
	}
}

void Board::setBoard()
{
	// Place pawns
	for(int i = 0; i < 8; i++)
	{
		board[1][i] = new member_ns::Pawn(member_ns::Color::WHITE); // White pawns
		board[6][i] = new member_ns::Pawn(member_ns::Color::BLACK); // Black pawns
	}

	// Place rooks
	board[0][0] = new member_ns::Rook(member_ns::Color::WHITE);
	board[0][7] = new member_ns::Rook(member_ns::Color::WHITE);
	board[7][0] = new member_ns::Rook(member_ns::Color::BLACK);
	board[7][7] = new member_ns::Rook(member_ns::Color::BLACK);

	// Place knights
	board[0][1] = new member_ns::Knight(member_ns::Color::WHITE);
	board[0][6] = new member_ns::Knight(member_ns::Color::WHITE);
	board[7][1] = new member_ns::Knight(member_ns::Color::BLACK);
	board[7][6] = new member_ns::Knight(member_ns::Color::BLACK);

	// Place bishops
	board[0][2] = new member_ns::Bishop(member_ns::Color::WHITE);
	board[0][5] = new member_ns::Bishop(member_ns::Color::WHITE);
	board[7][2] = new member_ns::Bishop(member_ns::Color::BLACK);
	board[7][5] = new member_ns::Bishop(member_ns::Color::BLACK);

	// Place queens
	board[0][3] = new member_ns::Queen(member_ns::Color::WHITE);
	board[7][3] = new member_ns::Queen(member_ns::Color::BLACK);
	// Place kings
	board[0][4] = new member_ns::King(member_ns::Color::WHITE);
	board[7][4] = new member_ns::King(member_ns::Color::BLACK);
	std::cout << "Board setup complete!" << std::endl;
}

member_ns::Piece* Board::getPiece(int x, int y) const
{
	if(x >= 0 && x < 8 && y >= 0 && y < 8)
	{
		return board[x][y];
	}
	return nullptr;
}

void Board::printBoard() const
{
	for(const auto& row : board)
	{
		for(const auto& piece : row)
		{
			if(piece)
			{
				cout << " " << piece->getSymbol() << "  ";
			}
			else
			{
				cout << "[ ]"
					 << " ";
			}
		}
		cout << endl;
	}
}
} // namespace board_ns
