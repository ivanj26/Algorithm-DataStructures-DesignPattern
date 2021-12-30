#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char firstNotRepeatingCharacter(std::string s)
{
	int len = s.length();
	char *arr = new char[len];
	std::fill_n(arr, len, '_');

	std::unordered_map<char, int> map;
	int idx = 0;

	for (int i = 0; i < len; i++)
	{
		char c = s[i];
		if (map.find(c) == map.end()) // if not duplicate
		{
			arr[idx] = c;
			map.insert(std::make_pair(c, idx));

			idx++;
		}
		else
		{
			int idx2 = map[c];
			arr[idx2] = '_';
		}
	}

	for (int i = 0; i < len; i++)
	{
		if (arr[i] != '_')
		{
			return arr[i];
		}
	}

	return '_';
}

char firstNotRepeatingCharacter2(std::string s)
{
	std::unordered_map<char, int> map;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s.at(i);
		bool found = map.find(c) != map.end();

		if (found)
		{
			map[c] = INT_MAX;
		}
		else
		{
			map.insert(std::make_pair(c, i));
		}
	}

	int idxMin = INT_MAX - 1;
	char res = '_';

	for (auto keyVal : map)
	{
		int index = keyVal.second;
		char c = keyVal.first;

		if (idxMin > index)
		{
			res = c;
			idxMin = index;
		}
	}

	return res;
}

int main(int argc, char const *argv[])
{
	std::cout << firstNotRepeatingCharacter("dsadsadbsjbdajksd") << std::endl;
	return 0;
}
