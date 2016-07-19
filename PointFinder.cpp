#include "PointFinder.h"


PointFinder::PointFinder(Point& startPoint, const Matrix& m, std::vector<List<Path>>* paths)
	:Finder(m, paths)
{
	bfsQueue.push(startPoint);
}

void PointFinder::findAndStore()
{
	matrix.setReachability(bfsQueue.front(), false);
	do
	{
		Point currPoint = bfsQueue.front();
		bfsQueue.pop();

		for (Direction dir = up; dir < NONE; dir = (Direction)(dir + 1))
		{
			if (canIGo(currPoint, dir))
			{
				Point adjecent = currPoint.getAdjacent(dir);
				if (matrix.isReachable(adjecent))
				{
					matrix.setReachability(adjecent, false);
					bfsQueue.push(adjecent);
					addPointToLists(adjecent);
				}
			}
		}
		reachablePoints.pushBack(currPoint);
	} while (!bfsQueue.isEmpty());
}

const List<Point>& PointFinder::getReachablePoints() const
{
	return reachablePoints;
}

void PointFinder::addPointToLists(const Point& pt)
{
	Path newPath;
	newPath.pushBack(pt);

	List<Path> paths;
	paths.pushBack(newPath);
	
	allPaths->push_back(paths);
}
