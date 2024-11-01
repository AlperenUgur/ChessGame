#include "game.hpp"
#include "member.hpp"
using namespace std;
namespace game_ns
{
Game* Game::instance = nullptr;

Game::Game()
	: isWhiteTurn(true)
{ }

Game* Game::getInstance()
{
	if(instance == nullptr)
	{
		instance = new Game();
	}
	return instance;
}

void Game::start()
{
	board.setBoard(); // Set up the board
	cout << "Chess Game Started!" << endl;
	board.printBoard();

	while(true)
	{
		playTurn(); // Take turns to play
	}
}

void Game::playTurn()
{
	int fromX, fromY, toX, toY;
	cout << (isWhiteTurn ? "White" : "Black") << " player, enter your move." << endl;

	cout << "Start X (0-7): ";
	cin >> fromX;
	cout << "Start Y (0-7): ";
	cin >> fromY;
	cout << "End X (0-7): ";
	cin >> toX;
	cout << "End Y (0-7): ";
	cin >> toY;
	member_ns::Color currentPlayerColor =
		isWhiteTurn ? member_ns::Color::WHITE : member_ns::Color::BLACK;
	member_ns::Piece* piece = board.getPiece(fromX, fromY);
	if(board.isMoveValid(piece, fromX, fromY, toX, toY, currentPlayerColor))
	{
		cout << "valid move!!!!" << endl;
		board.board[toX][toY] = piece; // Place the piece at the destination
		board.board[fromX][fromY] = nullptr; // Clear the starting position
		string move = (isWhiteTurn ? "White: " : "Black: ") + to_string(fromX) + "," +
					  to_string(fromY) + " -> " + to_string(toX) + "," + to_string(toY);
		isWhiteTurn = !isWhiteTurn; // Switch turns
		board.printBoard();
		moveHistory.add(move);
		moveHistory.print();
	}
	else
	{
		cout << "Invalid move, try again!" << endl;
	}
}
} // namespace game_ns
