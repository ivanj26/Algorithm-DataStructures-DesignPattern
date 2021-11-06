#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int sherlockAndAnagrams(string s) {
    unordered_map<string, int> map;
    int n = s.size();

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n - i; j++) {
            string sub = s.substr(j, i);

            sort(sub.begin(), sub.end());
            map[sub]++;
        }
    }

    int ans = 0;
    for (auto kv : map) {
        ans += kv.second * (kv.second - 1) / 2;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    cout << sherlockAndAnagrams("abba") << endl;
    cout << sherlockAndAnagrams("abcd") << endl;
    return 0;
}
