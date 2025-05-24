#include <iostream>
#include <string>
#include <vector>

using namespace std;

void markAsVisited(vector< vector<char> > &grid, int i, int j) {
    // Mark with another character
    grid[i][j] = '^';

    // Check top
    if (i > 0) {
        if (grid[i-1][j] == '*') {
            markAsVisited(grid, i-1, j);
        }
    }

    // Check bottom
    if (i < grid.size() - 1) {
        if (grid[i+1][j] == '*') {
            markAsVisited(grid, i+1, j);
        }
    }

    // Check left
    if (j > 0) {
        if (grid[i][j-1] == '*') {
            markAsVisited(grid, i, j-1);
        }
    }

    // Check right
    if (j < grid[0].size() - 1) {
        if (grid[i][j+1] == '*') {
            markAsVisited(grid, i, j+1);
        }
    }
}

int getNumberOfIsland(vector< vector<char> > &grid) {
    int count = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '*') {
                count++;
                markAsVisited(grid, i, j);
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector< vector<char> > grid;

    while (n > 0) {
        string line;
        getline(cin, line);

        if (line.empty()) {
            continue;
        }

        n--;

        vector<char> v(line.begin(), line.end());
        grid.push_back(v);
    }

    cout << endl;
    cout << "Current Map: " << endl;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (j == grid[i].size() - 1) {
               cout << grid[i][j];
               continue; 
            }
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Size of map: " << grid.size() << " " << grid[0].size() << endl; 
    cout << "Number of Island: " << getNumberOfIsland(grid) << endl;

    return 0;
}