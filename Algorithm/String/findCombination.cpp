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

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */