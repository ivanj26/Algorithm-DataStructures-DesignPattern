// You are given an integer array arr.
// Sort the integers in the array in ascending order by the number of 1's in their binary representation 
// and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

// Return the array after sorting it.

// Input: arr = [0,1,2,3,4,5,6,7,8]
// Output: [0,1,2,4,8,3,5,6,7]
// Explantion: [0] is the only integer with 0 bits.
// [1,2,4,8] all have 1 bit.
// [3,5,6] have 2 bits.
// [7] has 3 bits.
// The sorted array by bits is [0,1,2,4,8,3,5,6,7]

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct N {
    int val;
    int freq;
    N(int _val) : val(_val), freq(0) {}
};

vector<int> convertToVecInt(vector<N> &res) {
    vector<int> out;
    for (N n : res) {
        out.push_back(n.val);
    }

    return out;
}

vector<int> sortByBits(vector<int> &arr) {
    vector<N> res;

    for (int n : arr) {
        N entry(n);

        int f = 0;
        while (n > 0) {
            if (n & 1) {
                f++;
            }

            n >>= 1;
        }

        entry.freq = f;
        res.push_back(entry);
    }

    std::sort(res.begin(), res.end(), [](N i, N j) {
        if (i.freq == j.freq) {
            return i.val < j.val;
        }

        return i.freq < j.freq;
    });

    return convertToVecInt(res);
}

int main() {
    vector<int> t = {1024,512,256,128,64,32,16,8,4,2,1};
    vector<int> res = sortByBits(t);

    for (auto n : res) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}