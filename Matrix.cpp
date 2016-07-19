#include <iostream>

#include "Matrix.h"
#include "Point.h"

Matrix::Matrix(char** charMatrix, int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	
	matrix = new bool*[rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new bool[cols];
	}

	charToBool(charMatrix);
}

Matrix::Matrix(const Matrix& other)
{
	copy(other);
}

Matrix::~Matrix()
{
	clear();
}

const Matrix & Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

void Matrix::copy(const Matrix& other)
{
	rows = other.rows;
	cols = other.cols;
	matrix = new bool*[rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new bool[cols + 1];
		memcpy(matrix[i], other.matrix[i], (cols + 1) * sizeof(**matrix));
	} 
}

void Matrix::clear()
{
	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

bool Matrix::isReachable(const Point& p) const
{
	return matrix[p.row][p.col];
}

void Matrix::setReachability(const Point& p, bool isReachable)
{
	matrix[p.row][p.col] = isReachable;
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getCols() const
{
	return cols;
}

void Matrix::charToBool(char** charMatr)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (charMatr[i][j] == '.')
				matrix[i][j] = true;
			else if (charMatr[i][j] == '#')
				matrix[i][j] = false;
		}
	}
}

void Matrix::print() const
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (matrix[i][j])
				std::cout << ". ";
			else
				std::cout << "# ";
		}
		std::cout << std::endl;
	}
}

