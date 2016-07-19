#pragma once
#include <vector>

enum Direction
{
	up,
	right,
	down,
	left,
	NONE
};

struct Point
{
	int row;
	int col;

public:
	Point();
	Point(int, int);

public:
	Point getAdjacent(Direction);
	bool operator== (const Point&) const;
	void print() const;
};
