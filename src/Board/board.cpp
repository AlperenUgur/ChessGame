#include "board.hpp"
#include "member.hpp"
using namespace std;
namespace board_ns

{

Board::Board()
	: board(8, LinkedList<member_ns::Piece*>(8, nullptr))
{
	setBoard();
}

Board::~Board()
{
	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[i].size(); j++)
		{
			delete board[i][j];
		}
	}
}

void Board::setBoard()
{
	cout << "setBoard started!" << endl;
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

bool Board::isMoveValid(member_ns::Piece* piecePtr, int fromX, int fromY, int toX, int toY, member_ns::Color currentPlayerColor) {
	if (!piecePtr) {
		std::cout << "No piece at the starting position" << std::endl;
		return false;   
	}

	if (piecePtr->getColor() != currentPlayerColor) {
		std::cout << "You can only move your own pieces" << std::endl;
		return false;
	}

	// check color and piece who has already there
	member_ns::Piece* targetPiece = getPiece(toX, toY);
	if (targetPiece && targetPiece->getColor() == currentPlayerColor) {
		std::cout << "Cannot move to a square occupied by your own piece" << std::endl;
		return false;
	}
	if (!piecePtr->move(fromX, fromY, toX, toY)) {
		std::cout << "Invalid move for the piece" << std::endl;
		return false;
	}
	std::cout << "Moved piece from (" << fromX << ", " << fromY << ") to (" << toX << ", " << toY << ")" << std::endl;
	return true;
}

member_ns::Piece* Board::getPiece(int x, int y)
{
	if(x >= 0 && x < 8 && y >= 0 && y < 8)
	{
		return board[x][y];
	}
	return nullptr;
}

void Board::setPiece(int x, int y, member_ns::Piece* piecePtr)
{
	board[x][y] = piecePtr;
}

void Board::printBoard()
{
	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j])
			{
				cout << " " << board[i][j]->getSymbol() << "  ";
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
