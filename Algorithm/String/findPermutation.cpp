#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

using namespace std;

class PermutationIterator {
	private:
		vector<string> permutations;
		int ptr;

		string constructPermutations(string characters, int maxLength, string permutation = "")
		{
			if (permutation.length() == maxLength)
			{
				return permutation + " ";
			}

			string finalAnswers = "";
			for (int i = 0; i < characters.length(); i++)
			{
				char c = characters[i];
				string leftSubStr = characters.substr(0, i);
				string rightSubStr = characters.substr(i + 1);

				finalAnswers += constructPermutations(leftSubStr + rightSubStr, maxLength, permutation + c);
			}

			return finalAnswers;
		}

		vector<string> toVector(string perms, string delimiter = " ")
		{
			int start = 0;
			int end = perms.find(delimiter);
			vector<string> res;

			while (end != -1)
			{
				string perm = perms.substr(start, end - start);
				start = end + delimiter.size();
				end = perms.find(delimiter, start);

				res.push_back(perm);
			}

			return res;
		}

	public:
		PermutationIterator(string characters, int permutationLength) : ptr(0)
		{
			permutations = toVector(constructPermutations(characters, permutationLength));
		}

		bool hasNext()
		{
			return ptr < permutations.size();
		}

		string next()
		{
			assert(hasNext());
			return permutations[ptr++];
		}
};

class NumberPermutationIterator {
	private:
		vector< vector<int> > res;
		int ptr;

		void backtrack(vector<int> &nums, int maxLength, vector<int> temp, int i = 1)
		{
			if (temp.size() == maxLength)
			{
				res.push_back(temp);
				return;
			}

			for (int j = i; j <= nums.size(); j++)
			{
				temp.push_back(j);
				backtrack(nums, maxLength, temp, i + 1);
				temp.pop_back();
			}
		}

	public:
		NumberPermutationIterator(vector<int> nums, int k) : ptr(0)
		{
			vector<int> temp;
			backtrack(nums, k, temp);
		}

		bool hasNext()
		{
			return ptr < res.size();
		}

		vector<int> next()
		{
			return res[ptr++];
		}

		int size() { return res.size(); }
};

int main(int argc, char const *argv[])
{
	// PermutationIterator it("ABCD", 2);

	// // 4P2 = 4! / (4 - 2)! = 4 * 3 = 12 object

	// while (it.hasNext())
	// {
	// 	cout << it.next() << endl;
	// }

    vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);

    NumberPermutationIterator it(nums, 3);

	while (it.hasNext())
	{
		vector<int> res = it.next();

		for (int i = 0; i < res.size(); i++)
		{
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

	cout << "\n"
		 << it.size() << endl;
	return 0;
}
