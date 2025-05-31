#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Given a m x n grid filled with non-negative numbers.

// Dind a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

struct Loc {
    int x;
    int y;
    int distance;
    Loc(int _x, int _y) : x(_x), y(_y) {
        this->distance = 0;
    }

    Loc(int _x, int _y, int _distance) : x(_x), y(_y), distance(_distance) {

    }
};

class Solution {
    public:
        int minPathSum(vector<vector<int>> &grid) {
            queue<Loc> q;

            int i = 0, j = 0;

            // Insert the first element from top-left of grid
            q.push(Loc(i, j, grid[i][j]));

            int globalMinimum = INT_MAX;

            // Loop the queue until the queue is empty
            while (!q.empty()) {
                Loc loc = q.front();
                q.pop();

                // Check the stop condition, move to the next element
                //   If the x and y coordinates are located in the bottom-right of the grid
                //   Get the global minimum
                if ((loc.x == grid.size() - 1) && (loc.y == grid[0].size() - 1)) {
                    globalMinimum = min(globalMinimum, loc.distance);
                    continue;
                }

                // Check the right side of the current element
                // Move to right if the index is still in range
                if (loc.x < grid.size() - 1) {
                    q.push(Loc(loc.x + 1, loc.y, loc.distance + grid[loc.x + 1][loc.y]));
                }

                // Check the bottom side of the current element
                // Move to bottom if the index is still in range
                if (loc.y < grid[0].size() - 1) {
                    q.push(Loc(loc.x, loc.y + 1, loc.distance + grid[loc.x][loc.y + 1]));
                }
            }

            return globalMinimum;
        }
};