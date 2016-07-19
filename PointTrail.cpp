#include "PointTrail.h"
#include "ListIterator.h"


// NOTE: should create only the starting point
PointTrail::PointTrail(const Point& p) : Point(p)
{
}

PointTrail::PointTrail(const Point& p, PointTrail prev)
	: Point(p)
{
	prevPts = prev.prevPts;
	prevPts.pushBack((Point)prev);
}

bool PointTrail::isVisited(const Point& p) const
{
	if (!prevPts.isEmpty())
	{
		for (ListIterator<Point> it = prevPts.getIterator(); !it.isAtEnd(); ++it)
		{
			if (p == *it)
				return true;
		}
	}
	return false;
}

// pushing in the current object's list
// in order not to copy the list a second time.
// It works because nothing else will need the
// object anymore before destruction.
List<Point>& PointTrail::toPath()
{
	prevPts.pushBack(*this);
	return prevPts;
}

