#include "member.hpp"
#include <cmath>

namespace member_ns
{

// Pawn movement logic
bool Pawn::move(int fromX, int fromY, int toX, int toY)
{
	int direction = (getColor() == Color::WHITE) ? 1 : -1; // White moves up, Black moves down

	// Move forward by one square if the destination square is empty
	if(toX == fromX && toY == fromY + direction)
	{
		return true;
	}

	// Initial two-square move if both squares in front are empty
	if((getColor() == Color::WHITE && fromY == 1) || (getColor() == Color::BLACK && fromY == 6))
	{
		if(toX == fromX && toY == fromY + 2 * direction)
		{
			return true;
		}
	}

	// Diagonal capture move
	if((toX == fromX + 1 || toX == fromX - 1) && toY == fromY + direction)
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
