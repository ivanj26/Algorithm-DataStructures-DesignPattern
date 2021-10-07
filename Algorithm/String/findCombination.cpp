#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CombinationIterator
{
	private:
		vector<string> combinations;
		int index = 0;

		void backtrack(int maxLen, int index, string characters, string combination = "")
		{
			if (maxLen == combination.size())
			{
				combinations.push_back(combination);
				return;
			}

			string substr = characters.substr(index);
			for (auto c : substr)
			{
				if (combination.size() == 0 || (c - 'a' > combination[combination.length() - 1] - 'a'))
				{
					backtrack(maxLen, index + 1, characters, combination + c);
				}
				else
				{
					continue;
				}
			}
		}

	public:
		CombinationIterator(string characters, int combinationLength)
		{
			backtrack(combinationLength, 0, characters, "");
		}

		string next()
		{
			return combinations[index++];
		}

		bool hasNext()
		{
			return index < combinations.size();
		}
};

class NumberPermutationIterator {
    private:
        vector< vector<int> > res;
        int ptr;

        void backtrack(vector<int> &nums, int maxLength, vector<int> temp, int i = 1, int count = 0) {
            if (count == maxLength) {
                res.push_back(temp);
                return;
            }

            for (int j = i; j <= nums.size(); j++) {
                temp.push_back(j);
                backtrack(nums, maxLength, temp, j + 1, count + 1);
                temp.pop_back();
            }
        }

    public:
        NumberPermutationIterator(vector<int> nums, int k) : ptr(0) {
            vector<int> temp;
            backtrack(nums, k, temp);
        }

        bool hasNext() {
            return ptr < res.size();
        }

        vector<int> next() {
            return res[ptr++];
        }

        int size() { return res.size(); }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(int argc, char const *argv[])
{
    vector<int>  nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);

    NumberPermutationIterator it(nums, 3);

    while (it.hasNext()) {
        vector<int> res = it.next();
        
        for (int i = 0; i < res.size(); i++) {
            cout << res.at(i);
        }

        cout << endl;
    }

    /**
     * @brief n! / r! * (n - r)!
     * = 5! / 2! * (5-2)!
     * = (5! / 2! * 3!)
     * = 10;
     * 
     */

    cout << "\n" << it.size() << endl;
    return 0;
}
