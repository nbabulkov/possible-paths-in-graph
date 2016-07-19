#pragma once
#include "Point.h"
#include "List.h"
#include "Matrix.h"

typedef List<Point> Path;

class Finder
{
protected:
	Matrix matrix;
	std::vector<List<Path>>* allPaths;

public:
	Finder(const Matrix&, std::vector<List<Path>>*);
	Finder(const Finder&);
	const Finder& operator= (const Finder&);
	
public:
	virtual void findAndStore() = 0;
	const std::vector<List<Path>>* getAllPaths() const;

protected:
	void setAllPaths(std::vector<List<Path>>*);
	bool canIGo(const Point&, Direction) const;
};

