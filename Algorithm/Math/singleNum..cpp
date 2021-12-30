#include <vector>
#include <assert.h>
#include <set>

using namespace std;

int singleNumber(vector<int> arr)
{
	assert(arr.size() > 0);

	set<int> s;

	for (auto n : arr)
	{
		if (s.find(n) != s.end())
		{
			s.erase(n);
		}
		else
		{
			s.insert(n);
		}
	}

	return *s.begin();
}