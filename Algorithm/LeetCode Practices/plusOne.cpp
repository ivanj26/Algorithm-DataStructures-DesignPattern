#include <vector>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int lastIdx = digits.size() - 1;
    int val = digits[lastIdx];
    vector<int> copy = digits;

    if (val + 1 > 9) {
        int carry = 1;

        for (int i = lastIdx; i >= 0; i--) {
            if (carry > 0) {
                int sum = copy[i] + 1;
                if (sum > 9) {
                    sum = 0;
                } else {
                    carry = 0;
                }

                copy[i] = sum;
            }
        }

        if (carry > 0) {
            copy.insert(copy.begin(), 1);
        }
    } else {
        copy[lastIdx]++;
    }

    return copy;
}

int main(int argc, char const *argv[])
{
    vector<int> before = {9, 9, 9};
    vector<int> after = plusOne(before);

    for (int i = 0; i < after.size(); i++) {
        cout << after[i] << " ";
    }
    cout << endl;
    return 0;
}
