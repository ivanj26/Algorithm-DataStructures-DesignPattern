/**
 * @file minPathSum.cpp
 * @author Ivan Jonathan
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
 * 
 * @param grid matrix (vector of vector of integer)
 * @return int min path sum of given matrix
 */
int minPathSum(vector< vector<int> > &grid)
{
	int m = grid.size();
	int n = grid[0].size();

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (i == 0 && j > 0) {
				grid[i][j] += grid[i][j-1];
			} else if (i > 0 && j == 0) {
				grid[i][j] += grid[i-1][j];
			} else if (i > 0 && j > 0) {
				grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
			}
		}
	}

	return grid[m-1][n-1];
}

int main(int argc, char const *argv[])
{
	vector< vector<int> > grid;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(1);

	v2.push_back(1);
	v2.push_back(5);
	v2.push_back(1);

	v3.push_back(4);
	v3.push_back(2);
	v3.push_back(1);

	// 1 3 1
	// 1 5 1
	// 4 2 1

	// Answer: 1 + 3 + 1 + 1 + 1 = 7
	grid.push_back(v1);
	grid.push_back(v2);
	grid.push_back(v3);

	cout << "Min Path Sum: ";
	cout << minPathSum(grid) << endl;

	return 0;
}
