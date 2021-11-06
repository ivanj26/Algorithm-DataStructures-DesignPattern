#include <vector>
#include <stack>

using namespace std;

int equalStacks(vector<int> v1, vector<int> v2, vector<int> v3) {
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;

    stack<int> s1;
    stack<int> s2;
    stack<int> s3;

    for (int i = v1.size() - 1; i >= 0; i--) {
        int val = v1[i];

        c1 += val;
        s1.push(val);
    }

    for (int i = v2.size() - 1; i >= 0; i--) {
        int val = v2[i];

        c2 += val;
        s2.push(val);
    }

    for (int i = v3.size() - 1; i >= 0; i--) {
        int val = v3[i];

        c3 += val;
        s3.push(val);
    }

    while (!s1.empty() && !s2.empty() && !s3.empty()) {
        if (c1 == c2 && c2 == c3) {
            return c1;
        }

        if (c1 > c2 || c1 > c3) {
            int top = s1.top();
            c1 -= top;

            s1.pop();
        }

        if (c2 > c1 || c2 > c3) {
            int top = s2.top();
            c2 -= top;

            s2.pop();
        }

        if (c3 > c2 || c3 > c1) {
            int top = s3.top();
            c3 -= top;

            s3.pop();
        }
    }

    return 0;
}