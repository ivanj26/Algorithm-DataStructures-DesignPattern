#include <iostream>
#include <string>

using namespace std;

class Person {
	private:
		string first_name;
		string last_name;
	public:
		Person(string f, string l)
		{
			this->first_name = f;
			this->last_name = l;
		}

		string get_first_name() const {
			return this->first_name;
		}

		string get_last_name() const {
			return this->last_name;
		}
};

ostream& operator<<(ostream& os, Person& p) {
    os << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
    return os;
}

int main(int argc, char const *argv[])
{
	string f, l, event;
	cin >> f >> l >> event;

	auto p = Person(f, l);
	cout << p << " " << event << endl;
	return 0;
}
