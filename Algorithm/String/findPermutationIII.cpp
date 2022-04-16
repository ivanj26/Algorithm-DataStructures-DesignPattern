#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        vector<int> res;

        int digit(int number)
        {
            int d = 1;
            int base = 10;

            while (number / base > 0)
            {
                d++;
                base *= 10;
            }

            return d;
        }

        void permutateUtil(string &nums, bool visited[], int temp = 0)
        {
            if (digit(temp) == nums.size())
            {
                res.push_back(temp);
                return;
            }


            // 123
            // i = 0 -> temp = 1
            // i = 1 -> temp = 12
            // i = 2 -> temp = 123

            for (int i = 0; i < nums.size(); i++)
            {
                char c = nums[i];
                int val = c - '0';

                if (visited[i]) {
                    continue;
                }

                visited[i] = true;

                temp *= 10;
                temp += val;

                permutateUtil(nums, visited, temp);

                temp /= 10;
                visited[i] = false;
            }
        }

    public:
        vector<int> permutate(string nums)
        {
            bool visited[nums.length()];
            fill_n(visited, nums.length(), false);

            permutateUtil(nums, visited);

            return res;
        }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> res = sol.permutate("54321");

    for (int num : res)
    {
        cout << num << endl;
    }

    cout << endl;
    cout << "Jumlah hasil: " << res.size() << endl;

    // Permutasi: n! / (n-r)!
    // r = 3
    // 5! / 0! = 120

    return 0;
}
