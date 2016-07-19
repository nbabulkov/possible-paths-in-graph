#pragma once
#include "List.h"
#include "Queue.h"
#include "Matrix.h"
#include "Finder.h"

class PointFinder: public Finder
{
private:
	Queue<Point> bfsQueue;
	List<Point> reachablePoints;

public:
	PointFinder(Point&, const Matrix&, std::vector<List<Path>>*);

public:
	virtual void findAndStore();

	const List<Point>& getReachablePoints() const;

private:
	void addPointToLists(const Point&);
};

