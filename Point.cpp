#include <iostream>
#include "Point.h"

Point::Point()
{
	row = col = 0;
}

Point::Point(int row, int col)
{
	this->row = row;
	this->col = col;
}

Point Point::getAdjacent(Direction dir)
{
	Point p(*this);
	switch (dir)
	{
	case up:
		--p.row;
		break;

	case right:
		++p.col;
		break;

	case down:
		++p.row;
		break;

	case left:
		--p.col;
		break;
	}
	return p;
}

bool Point::operator==(const Point& p) const
{
	return (row == p.row) && (col == p.col);
}

void Point::print() const
{
	printf("(%d, %d)", row, col);
}



