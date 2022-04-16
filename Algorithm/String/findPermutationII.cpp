#include <vector>
#include <iostream>

using namespace std;

class Solution {
    private:
        vector< vector<int> > res;
        bool *visited;

        void search(vector<int> &nums, vector<int> temp) {
            if (temp.size() == nums.size()) {
                res.push_back(temp);

                return;
            }

            for (int i = 0; i < nums.size(); i++) {
                if (visited[i]) continue;

                temp.push_back(nums[i]);
                visited[i] = true;

                search(nums, temp);
                temp.pop_back();

                visited[i] = false;
            }
        }
    public:
        vector< vector<int> > permutate(vector<int> &nums) {
            int n = nums.size();
            visited = new bool[n];
            fill_n(visited, n, false);

            vector<int> temp;

            search(nums, temp);

            return res;
        }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector< vector<int> > result = sol.permutate(v);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    cout << "Count: " << result.size() << endl;

    return 0;
}
