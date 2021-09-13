#include <iostream>
#include <string>
#include <unordered_map>

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

int main(int argc, char const *argv[])
{
	std::cout << firstNotRepeatingCharacter("dsadsadbsjbdajksd") << std::endl;
	return 0;
}
