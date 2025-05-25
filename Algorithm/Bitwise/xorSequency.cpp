#include <vector>

using namespace std;

long xorSequence(long l, long r) {
    vector<long> A;
    A.push_back(0);

    long sum = 0;
    for (long i = 1; i <= r; i++) {
        long currVal = A[i-1] ^ i;
        if (i >= l) {
            sum = sum ^ currVal;
        }

        A.push_back(currVal);
    }

    return sum;
}