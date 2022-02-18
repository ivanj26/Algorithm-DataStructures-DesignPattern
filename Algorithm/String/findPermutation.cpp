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

class Permutator {
	protected:
		bool *visited;
		vector< vector<int> > res;

		virtual void backtrack(vector<int>& nums, vector<int> temp) = 0;
	public:
		virtual ~Permutator()
		{
			delete[] visited;
		}
		vector<vector<int>> permutate(vector<int>& nums)
		{
			// initialize visited array elements with false value
			int size = nums.size();
			visited = new bool[size];
			fill_n(visited, size, false);

			this->backtrack(nums, {});

			return this->res;
		}
};

class Permutation: public Permutator {
	private:
		void backtrack(vector<int> &nums, vector<int> temp)
		{
			// if the temp size is equal to original array size
			// push it to result
			if (temp.size() == nums.size())
			{
				res.push_back(temp);
				return;
			}

			for (int i = 0; i < nums.size(); i++)
			{
				// make sure only un-visited element pushed into temp variable
				if (visited[i])
				{
					continue; // need to by pass if already visited
				}

				temp.push_back(nums[i]);
				visited[i] = true;

				this->backtrack(nums, temp);

				temp.pop_back();
				visited[i] = false;
			}
		}
	
	public:
		Permutation() : Permutator() {}
};

class PermutationWithRepitition: public Permutator {
	private:
		void backtrack(vector<int>& nums, vector<int> temp)
		{
			if (temp.size() == nums.size())
			{
				res.push_back(temp);
				return;
			}

			for (int i = 0; i < nums.size(); i++)
			{
				temp.push_back(nums[i]);
				this->backtrack(nums, temp);
				temp.pop_back();
			}
		}
	public:
		PermutationWithRepitition() : Permutator() {}
};

class PermutatorBuilder {
	public:
		static Permutator* build(string type = "no-repeat") {
			if (type == "repeat") {
				return new PermutationWithRepitition();
			} else {
				return new Permutation();
			}
		}
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
	// nums.push_back(4);
	// nums.push_back(5);

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

	Permutator *p = PermutatorBuilder::build();
	vector<vector<int>> res = p->permutate(nums);

	for (vector<int> v : res) {
		for (int num : v) {
			cout << num << " ";
		}

		cout << endl;
	}

	delete p;

	return 0;
}
