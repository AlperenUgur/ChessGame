#include "member.hpp"
#include <cmath>
#include <iostream>

using namespace std;

namespace member_ns
{

// Pawn movement logic
bool Pawn::move(int fromX, int fromY, int toX, int toY)
{
	int direction = (getColor() == Color::WHITE) ? 1 : -1; // White moves up, Black moves down
	cout << direction << endl;

	// Move forward by one square if the destination square is empty
	if(toX == fromX + direction && toY == fromY)
	{
		return true;
	}

	// Initial two-square move if both squares in front are empty
	if((getColor() == Color::WHITE && fromX == 1) || (getColor() == Color::BLACK && fromX == 6))
	{
		if(toX == fromX + 2 * direction && toY == fromY)
		{
			return true;
		}
	}

	// Diagonal capture move
	if((toY == fromY + 1 || toY == fromY - 1) && toX == fromX + direction)
	{
		return true;
	}

	return false;
}

// Rook movement logic (horizontal or vertical moves)
bool Rook::move(int fromX, int fromY, int toX, int toY)
{
	return (fromX == toX || fromY == toY);
}

// Knight movement logic ("L" shape)
bool Knight::move(int fromX, int fromY, int toX, int toY)
{
	int dx = abs(toX - fromX);
	int dy = abs(toY - fromY);
	return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

// Bishop movement logic (diagonal moves)
bool Bishop::move(int fromX, int fromY, int toX, int toY)
{
	return abs(toX - fromX) == abs(toY - fromY);
}

// Queen movement logic (combination of Rook and Bishop moves)
bool Queen::move(int fromX, int fromY, int toX, int toY)
{
	return (fromX == toX || fromY == toY || abs(toX - fromX) == abs(toY - fromY));
}

// King movement logic (one square in any direction)
bool King::move(int fromX, int fromY, int toX, int toY)
{
	int dx = abs(toX - fromX);
	int dy = abs(toY - fromY);
	return (dx <= 1 && dy <= 1);
}

} // namespace member_ns
