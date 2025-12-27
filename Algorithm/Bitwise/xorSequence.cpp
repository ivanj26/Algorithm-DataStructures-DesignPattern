// An array "A" , is defined as follows:
// A0 = 0
// A1 = A0 ^ 1
// Ax = A(x-1) ^ x for all x > 0 where ^ is the symbol for XOR

// You will be given a left and right index (l and r).
// You must determine the XOR sum of the segment from l to r.

long xorSequence(long l, long r) {
    long prev = 0;
    long result = 0;

    for (long i = 1; i <= r; i++) {
        auto curr = prev ^ i;
        if (i >= l) {
            result ^= curr;
        }

        prev = curr;
    }

    return result;
}