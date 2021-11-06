#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> map;

    for (auto val : magazine) {
        const bool found = map.find(val) != map.end();

        if (found) {
            map[val]++;
        } else {
            map[val] = 1;
        }
    }

    int count = 0;
    for (auto val : note) {
        const bool found = map.find(val) != map.end();

        if (found) {
            if (map[val] > 0) {
                count++;
                map[val]--;
            }
        }
    }

    if (count == note.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}