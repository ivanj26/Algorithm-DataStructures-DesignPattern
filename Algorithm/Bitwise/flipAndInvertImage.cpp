#include <vector>

using namespace std;

// Example 1:
// Input: image = [[1,1,0],[1,0,1],[0,0,0]]
// Output: [[1,0,0],[0,1,0],[1,1,1]]
// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

// Example 2:
// Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
// Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 

class Solution {
    private:
        vector<int> reverse(vector<int> &v) {
            for (int i = 0; i < v.size() / 2; i++) {
                swap(v[i], v[v.size()-i-1]);
            }

            return v;
        }

        vector<int> invert(vector<int> &v) {
            vector<int> out; 
            for (int n : v) {
                out.push_back(n ^ 1);
            }

            return out;
        }

    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
            vector<vector<int>> out;
            for (int i = 0; i < image.size(); i++) {
                vector<int> reversed = reverse(image[i]);
                out.push_back(invert(reversed));
            }

            return out;
        }
};