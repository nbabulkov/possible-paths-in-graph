#pragma once
#include "Point.h"
#include "PointTrail.h"
#include "List.h"
#include "Queue.h"
#include "Matrix.h"
#include "Finder.h"

class PathFinder: public Finder
{
private:
	Queue<PointTrail> bfsQueue;
	
public:
	PathFinder(const Point&, const Matrix&, std::vector<List<Path>>* );
	
public:
	virtual void findAndStore();

private:
	void addPathToLists(PointTrail&);
	 
};

