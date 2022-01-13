#include <vector>
#include <string>
#include <iostream>

using namespace std;

string timeConvert(string s) {
	string delim = ":";
	string timeType = s.substr(s.length() - 2);

	s = s.substr(0, s.length() - 2);

	int start = 0;
	int end = s.find(delim);
	vector<int> v;

	while (end != std::string::npos) {
		string subs = s.substr(start, end - start);
		int val = std::stoi(subs);

		v.push_back(val);

		start = end + delim.length();
		end = s.find(delim, start);
	}

	v.push_back(
		std::stoi(s.substr(s.length() - 2))
	);

	string res;
	for (int i = 0; i < v.size(); i++) {
		int val = v[i];

		if (i == 0) {
			if (timeType == "PM") {
				if (v[i] != 12) {
					val += 12;
				}
			} else { // if AM
				if (v[i] == 12) {
					val = 0;
				}
			}
		}

		if (i > 0) {
			res += ":";
		}
		
		if (val < 10) {
			res += ("0" + to_string(val));
		} else {
			res += to_string(val);
		}
	}

	return res;
}

int main(int argc, char const *argv[])
{
	cout << timeConvert("07:05:06PM") << endl;
	return 0;
}
