#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string s;
    string res;
    set<int> set;
    set.insert();
    set.find()
    getline(cin, s);

    char prev = '&';
    for (int i = 0; i < s.length(); i++) {
        char curr = s.at(i);
        if (prev == ' ') {
            if (curr != ' ')) {
                res.push_back(curr);
            }
        } else {
            res.push_back(curr);
        }

        prev = curr;
    }

    cout << res << endl;
}