#include <vector>
using namespace std;

// Given an m x n matrix, return all elements of the matrix in spiral order.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

class Solution
{
    public:
        vector<int> spiralOrder(vector<vector<int>> &matrix) {
            int direction = 0;
            int m = matrix.size();
            int n = matrix[0].size();

            bool isStop = false;
            vector<int> res;
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            int i = 0, j = 0;
            int total = m * n;
            int curr = 0;
            while (!isStop)
            {
                // End condition
                if (curr == total)
                {
                    isStop = true;
                    continue;
                }

                // Reset direction if >= 360
                if (direction >= 360)
                {
                    direction -= 360;
                }

                // Check visited matrix
                if (visited[i][j])
                {
                    if (direction == 270)
                    {
                        i++;
                        j++;
                    }
                    else if (direction == 0)
                    {
                        j--;
                        i++;
                    }
                    else if (direction == 90)
                    {
                        i--;
                        j--;
                    }
                    else if (direction == 180)
                    {
                        j++;
                        i--;
                    }

                    direction += 90;
                    continue;
                }

                visited[i][j] = true;
                curr++; // counter

                // Right direction
                if (direction == 0)
                {
                    int val = matrix[i][j];
                    if (j < n - 1)
                    {
                        j++;
                    }
                    else if (j == n - 1)
                    {
                        direction += 90;
                        i++;
                    }

                    res.push_back(val);
                }
                else if (direction == 90)
                { // Down direction
                    int val = matrix[i][j];
                    if (i < m - 1)
                    {
                        i++;
                    }
                    else if (i == m - 1)
                    {
                        direction += 90;
                        j--;
                    }

                    res.push_back(val);
                }
                else if (direction == 180)
                { // Left direction
                    int val = matrix[i][j];
                    if (j > 0)
                    {
                        j--;
                    }
                    else if (j == 0)
                    {
                        direction += 90;
                        i--;
                    }

                    res.push_back(val);
                }
                else if (direction == 270)
                { // Up direction
                    int val = matrix[i][j];
                    if (i > 0)
                    {
                        i--;
                    }
                    else if (i == 0)
                    {
                        direction += 90;
                        j++;
                    }

                    res.push_back(val);
                }
            }

            return res;
        }
};