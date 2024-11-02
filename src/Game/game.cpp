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

void Game::play()
{
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
	member_ns::Piece* piecePtr = board.getPiece(fromX, fromY);
	if(board.isMoveValid(piecePtr, fromX, fromY, toX, toY, currentPlayerColor))
	{
		cout << "valid move!!!!" << endl;
		board.setPiece(toX, toY, piecePtr); // Place the piece at the destination
		board.setPiece(fromX, fromY, nullptr); // Clear the starting position
		string move = (isWhiteTurn ? "White: " : "Black: ") + to_string(fromX) + "," +
					  to_string(fromY) + " -> " + to_string(toX) + "," + to_string(toY);
		isWhiteTurn = !isWhiteTurn; // Switch turns
		board.printBoard();
	}
	else
	{
		cout << "Invalid move, try again!" << endl;
	}
}
} // namespace game_ns
