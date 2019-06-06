// 82_Path sumthreeways.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

constexpr auto height = 5;;
constexpr auto width = 5;;

void FindPath(int i, int j, int sum, int matrix[height][width], int *minimum)
{
	if (i < height && j < width)
		sum = sum + matrix[i][j];
	if (j == width - 1)
	{
		if (*minimum == 0)
			*minimum = sum;
		else if (sum < *minimum)
			*minimum = sum;
		return;
	}
	if (i > 0 && j < width - 1)
	{
		FindPath(i - 1, j, sum, matrix, minimum);
	}
	if (j < width - 1)
	{
		FindPath(i, j + 1, sum, matrix, minimum);
	}
	if (i > 0)
	{
		FindPath(i - 1, j, sum, matrix, minimum);
	}
}

int main()
{
	int matrix[height][width];
	int minimum = 0;
	int i;
	matrix[0][0] = 131;
	matrix[0][1] = 673;
	matrix[0][2] = 234;
	matrix[0][3] = 103;
	matrix[0][4] = 18;

	matrix[1][0] = 201;
	matrix[1][1] = 96;
	matrix[1][2] = 342;
	matrix[1][3] = 965;
	matrix[1][4] = 150;

	matrix[2][0] = 630;
	matrix[2][1] = 803;
	matrix[2][2] = 746;
	matrix[2][3] = 422;
	matrix[2][4] = 111;

	matrix[3][0] = 537;
	matrix[3][1] = 699;
	matrix[3][2] = 497;
	matrix[3][3] = 121;
	matrix[3][4] = 956;

	matrix[4][0] = 805;
	matrix[4][1] = 732;
	matrix[4][2] = 524;
	matrix[4][3] = 37;
	matrix[4][4] = 331;

	for (i = 0; i < height; i++)
		FindPath(i, 0, 0, matrix, &minimum);

	FindPath(0, 0, 0, matrix, &minimum);
	printf("\n%d", minimum);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
