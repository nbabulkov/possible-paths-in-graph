#pragma once
#include "Point.h"

class Matrix
{
private:
	int rows;
	int cols;
	bool** matrix;

public:
	Matrix(char**, int, int);
	Matrix(const Matrix&);
	~Matrix();
	const Matrix& operator= (const Matrix&);

private:
	void copy(const Matrix&);
	void clear();

public:
	bool isReachable(const Point&) const;
	void setReachability(const Point&, bool);

	int getRows() const;
	int getCols() const;

	void charToBool(char**);
	void print() const;
};

