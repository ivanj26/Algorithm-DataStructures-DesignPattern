#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class NestedInteger
{
	private:
		int value = INT_MIN;
		vector<NestedInteger> list;

	public:
		NestedInteger() {}

		void setInteger(int value)
		{
			this->value = value;
		}

		bool isInteger() const
		{
			return list.size() == 0 ? true : false;
		}

		int getInteger() const
		{
			return value;
		}

		const vector<NestedInteger> &getList() const
		{
			return list;
		}

		void setList(vector<NestedInteger> &list)
		{
			this->list = list;
		}
};

class NestedListIterator
{
	private:
		vector<int> v;
		int ptr;

		void constructFlattenList(const vector<NestedInteger> &list)
		{
			for (NestedInteger obj : list)
			{
				if (obj.isInteger())
				{
					v.push_back(obj.getInteger());
				}
				else
				{
					constructFlattenList(obj.getList());
				}
			}
		}

	public:
		NestedListIterator(vector<NestedInteger> &list)
		{
			constructFlattenList(list);
			ptr = 0;
		}

		bool hasNext()
		{
			return ptr < v.size();
		}

		int next()
		{
			if (this->hasNext())
			{
				return v[ptr++];
			}

			return -1;
		}

		int value()
		{
			return v.at(ptr);
		}
};

int main(int argc, char const *argv[])
{
	vector<NestedInteger> list;

	vector<NestedInteger> int11;
	NestedInteger int111;
	NestedInteger int112;
	int111.setInteger(1);
	int112.setInteger(1);

	int11.push_back(int111);
	int11.push_back(int112);

	NestedInteger int1;
	int1.setList(int11);

	NestedInteger int2;
	int2.setInteger(2);

	list.push_back(int1);
	list.push_back(int2);
	list.push_back(int1);
	list.push_back(int2);
	list.push_back(int2);
	list.push_back(int1);

	NestedListIterator it(list);

	while (it.hasNext())
	{
		cout << it.value() << endl;
		it.next();
	}

	return 0;
}
