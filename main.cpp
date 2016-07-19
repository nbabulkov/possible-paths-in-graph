// Date: 29.11.2015
// Nikolay Babulkov FN-45088, Group IV, Informatics, FMI 
// Assignment 2, SDP
//
// All possible paths in a matrix(grapth) sorted by length.
//

#include <iostream>
#include "List.h"
#include "Point.h"
#include "Matrix.h"
#include "PointFinder.h"
#include "PathFinder.h"

const int BUFFSIZE = 32;

bool enteredIsPositiveInt(int& i)
{
	int temp;
	std::cin >> temp;
	if (temp > 0)
	{
		i = temp;
		return true;
	}
	return false;
}

void enterCoordinates(int& x, int& y)
{
	std::cout << "\nEnter the following two coordinates: " << std::endl;

	if (!enteredIsPositiveInt(x))
		enterCoordinates(x, y);

	if (!enteredIsPositiveInt(y))
		enterCoordinates(x, y);
}

char** createMatrix(int rows, int cols)
{
	char** str = new char*[rows];
	for (int i = 0; i < rows; ++i)
	{
		str[i] = new char[cols + 1];
	}
	return str;
}

void freeMatrix(char** str, int rows)
{
	for (int i = 0; i < rows; ++i)
		delete[] str[i];
	delete[] str;
}

bool isContentCorrect(char* str)
{
	int size = strlen(str);
	for (int i = 0; i < size; ++i)
	{
		if (str[i] != '.' || str[i] != '#')
		{
			return false;
		}
	}
	return true;
}

void fillMatrix(char** matrix, int rows, int cols)
{
	std::cout << "\nFill the matrix with \"#\" or \".\": " << std::endl;
	for (int i = 0; i < rows; ++i)
	{
	//	std::cin.clear();
	//	std::cin.ignore();
		bool isCorrect = true;
		do 
		{
			std::cout << i + 1 << ") ";
			std::cin.getline(matrix[i], cols + 1);
			isCorrect = isContentCorrect(matrix[i]);
		} while (strlen(matrix[i]) != cols && isCorrect);
	}
}

void printAllPaths(std::vector<List<Path>>& pVec)
{
	int size = pVec.size();
	for (int i = 0; i < size; ++i)
	{
		(pVec.at(i)).print();
	}
}

int main()
{
/*	int rows, cols;
	enterCoordinates(rows, cols);

	char** charMatrix = createMatrix(rows, cols);
	fillMatrix(charMatrix, rows, cols);

	int x, y;
	enterCoordinates(x, y);
*/
	Point start(0, 0);

	const int rows = 4,
			  cols = 4;
	char* charMatrix[rows] = 
	{
		{ "...." },
		{ "...." },
		{ "...." },
		{ "...." }
	};

	Matrix matrix(charMatrix, rows, cols);
	std::vector<List<Path>> paths;	

	PointFinder ptFinder(start, matrix, &paths);
	ptFinder.findAndStore();

	List<Point> reachedPoints = ptFinder.getReachablePoints();
	reachedPoints.print();

	std::cout << std::endl;
//	matrix.print();

	PathFinder pathFinder(start, matrix, &paths);
	pathFinder.findAndStore();

	printAllPaths(paths);

//	freeMatrix(charMatrix, rows);
	return 0;
}