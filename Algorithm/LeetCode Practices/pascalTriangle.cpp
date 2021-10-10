#include <vector>
#include <iostream>

using namespace std;

vector< vector<int> > generate(int numRows) {
    vector< vector<int> > v(numRows);

    v[0].push_back(1);

    for (int i = 1; i < numRows; i++) {
        v[i].push_back(1);

        if (i >= 2) {
            for (int j = 1; j < i; j++) {
                v[i].push_back(
                    v[i-1][j-1] + v[i-1][j]
                );
            }
        }

        v[i].push_back(1);
    }

    return v;
}


int main(int argc, char const *argv[])
{
    vector< vector<int> > res = generate(10);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
