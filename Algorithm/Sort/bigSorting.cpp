#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool numericStringCompare(const string& s1, const string& s2) {
    if (s1.length() == s2.length()) {
        return s1 < s2;
    }

    return s1.length() < s2.length();
}

vector<string> bigSorting(vector<string> unsorted) {
    std::sort(unsorted.begin(), unsorted.end(), numericStringCompare);

    return unsorted;
}
