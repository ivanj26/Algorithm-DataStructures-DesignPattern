#include <vector>
#include <queue>

using namespace std;

struct Position {
    vector<int> coor;
    int totalDistance;
    Position(int x, int y, int _totalDistance) {
        coor.push_back(x);
        coor.push_back(y);
        totalDistance = _totalDistance;
    }

    Position(vector<int> _coor, int _totalDistance) {
        coor = _coor;
        totalDistance = _totalDistance;
    }
};

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<Position> q;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        q.push(Position(entrance[0], entrance[1], 0));

        int minimum = INT_MAX;
        while (!q.empty()) {
            Position pos = q.front();
            int x = pos.coor[0];
            int y = pos.coor[1];

            if (visited[x][y]) {
                q.pop();
                continue;
            }

            visited[x][y] = true;

            if ((x == 0 || y == 0 || y == maze[0].size()-1 || x == maze.size()-1) && pos.totalDistance != 0) {
                minimum = min(pos.totalDistance, minimum);
                continue;
            }

            // Check UP direction
            if (y > 0) {
                if (maze[x][y-1] == '.') {
                    q.push(Position(x, y-1, pos.totalDistance + 1));
                }
            }

            // Check DOWN direction
            if (y < maze[0].size() - 1) {
                if (maze[x][y+1] == '.') {
                    q.push(Position(x, y+1, pos.totalDistance + 1));
                }
            }

            // Check LEFT direction
            if (x > 0) {
                if (maze[x-1][y] == '.') {
                    q.push(Position(x-1, y, pos.totalDistance + 1));
                }
            }

            // Check RIGHT direction
            if (x < maze.size() - 1) {
                if (maze[x+1][y] == '.') {
                    q.push(Position(x+1, y, pos.totalDistance + 1));
                }
            }
        
            q.pop();
        }

        return minimum == INT_MAX ? -1 : minimum;
    }
};