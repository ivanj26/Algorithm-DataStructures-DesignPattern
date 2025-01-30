#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDNASequence(string s) {
    unordered_map<string, int> mp;

    for (int i = 0; i < s.length(); i++) {
        string subs = s.substr(i, 10);
        mp[subs]++;
    }

    vector<string> res;
    for (auto kv : mp) {
        if (kv.second > 1) {
            res.push_back(kv.first);
        }
    }

    return res;
}

int main() {
    string s;
    cin >> s;

    vector<string> res = findRepeatedDNASequence(s);
    for (auto s : res) {
        cout << s << endl;
    }

    return 0;
}