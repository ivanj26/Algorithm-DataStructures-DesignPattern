#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector< vector<int> > printBinSquare(int n) {
    vector< vector<int> > res;
    std::unordered_map< int, vector<int> > map;

    vector<int> v;

    // O (2 * n) => O(n)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (v.size() > 0) {
                int last = v.at(v.size() - 1);
                if (last == 0) {
                    v.push_back(1);
                } else {
                    v.push_back(0);
                }
            } else {
                v.push_back(i % 2);
            }
        }

        map[i] = v;

        v.clear();
    }

    // O (n)
    for (int i = 0; i < n; i++) {
        res.push_back(map[i % 2]);
    }

    return res; // Time complexity : O(n), Space: O(n)
}

int main(int argc, char const *argv[])
{
    /* code */
    vector< vector<int> > res = printBinSquare(3);

    for (vector<int> v : res) {
        for (auto val : v) {
            cout << val;
        }
        cout << endl;
    }

    return 0;
}
