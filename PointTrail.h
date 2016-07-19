#pragma once
#include "Point.h"
#include "List.h"

class PointTrail: public Point
{
	private:
		List<Point> prevPts;

	public:
		PointTrail(const Point&);
		PointTrail(const Point&, PointTrail prev);

public:
	bool isVisited(const Point&) const;
	List<Point>& toPath();
};

