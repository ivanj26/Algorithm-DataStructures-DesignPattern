#include <set>
#include <vector>
using namespace std;

/**
 * Check duplicate if:
 * Input range  : 0 <= a.length <= 10^5
 * Range elmt   : -2 * 10^9 <= a[i] 2 * 10^9
 **/
int containsDuplicate(vector<int> a) {
    set<int> s;

    for (auto el : a)
    {
        if (s.find(el) != s.end()) return true;
        s.insert(el);
    }

    return false;
}