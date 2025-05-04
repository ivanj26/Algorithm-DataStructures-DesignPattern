#include <vector>
using namespace std;

class Solution {
    private:
        void lookup(vector<vector<int>> &rooms, int pos, vector<bool> &visited) {
            vector<int> keys = rooms[pos];
            for (int j = 0; j < keys.size(); j++) {
                int key = keys[j];
                if (!visited[key]) {
                    visited[key] = true;
                    lookup(rooms, key, visited);
                }
            }
        }
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            vector<bool> visited(rooms.size(), false);
            
            // Lookup is a DFS style to enter the room using DFS style
            int start = 0;
            visited[0] = true;
            lookup(rooms, start, visited);

            // Check which rooms has visited or not
            // If any of them is not yet visited , it means you can't visit all rooms
            for (int i = 0; i < rooms.size(); i++) {
                if (!visited[i]) {
                    return false;
                }
            }

            return true;
        }
};

