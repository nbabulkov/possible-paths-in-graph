#include "PathFinder.h"

PathFinder::PathFinder(const Point& startingPoint, const Matrix& m, std::vector<List<Path>>* paths)
	: Finder(m, paths)
{
	PointTrail start = startingPoint;
	bfsQueue.push(start);
}

void PathFinder::findAndStore()
{
	do
	{
		PointTrail currPTrail = bfsQueue.front();
		bfsQueue.pop();

		for (Direction dir = up; dir < NONE; dir = (Direction)(dir + 1))
		{
			if (canIGo(currPTrail, dir))
			{
				Point adjacent = currPTrail.getAdjacent(dir);
				if (matrix.isReachable(adjacent) && !currPTrail.isVisited(adjacent))
				{
					PointTrail adjPTrail(adjacent, currPTrail);
					bfsQueue.push(adjPTrail);
					addPathToLists(adjPTrail);
				}
			}
		}
	} while (!bfsQueue.isEmpty());
}

void PathFinder::addPathToLists(PointTrail& trail)
{
	unsigned size = allPaths->size();
	for (unsigned i = 0; i < size; ++i)
	{
		List<Path>& pathList = allPaths->at(i);

		// the == operator takes the Point from the PointTrail in the left
		// and the first Point in the first Path in the List on the right
		// and compares them as 2 points
		if ((Point)trail == pathList.front().front())
		{
			pathList.pushBack(trail.toPath());
			break;
		}
	}
}
