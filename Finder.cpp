#include "Finder.h"

Finder::Finder(const Matrix& m, std::vector<List<Path>>* paths)
	: matrix(m), allPaths(paths)
{
}

Finder::Finder(const Finder& f)
	: matrix(f.matrix)
{
	*allPaths = *allPaths;
}

const Finder & Finder::operator=(const Finder& f)
{
	if (this != &f)
	{
		matrix = f.matrix;
		*allPaths = *f.allPaths;
	}
	return *this;
}

inline void Finder::setAllPaths(std::vector<List<Path>>* paths)
{
	allPaths = paths;
}

inline const std::vector<List<Path>>* Finder::getAllPaths() const
{
	return allPaths;
}

bool Finder::canIGo(const Point& currPoint, Direction dir) const
{
	switch (dir)
	{
	case up:
		return currPoint.row - 1 >= 0;

	case right:
		return currPoint.col + 1 < matrix.getCols();

	case down:
		return currPoint.row + 1 < matrix.getRows();

	case left:
		return currPoint.col - 1 >= 0;

	default:
		throw std::out_of_range("Wrong direction!");
	}
}