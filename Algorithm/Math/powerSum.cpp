// Assume that the exponent is positive integer with range X >= 0
long powUtil(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }

    // If the exponent value is odd
    // Just do recursion by multiply to current base
    if (exponent & 1) {
        return base * powUtil(base, exponent - 1);
    } else {
        return powUtil(base * base, exponent / 2);
    }
}

int powerSumHelper(long targetBase, int exponent, int base) {
    // Base recursion: if the target sum is zero
    // Return 1 to indicate as a valid possible way
    if (targetBase == 0) {
        return 1;
    }

    int possibleWays = 0;

    // Recursion: Check the possible ways by subtract the target base with current power value
    while (powUtil(base, exponent) <= targetBase) {
        long currExp = powUtil(base, exponent);
        possibleWays += powerSumHelper(targetBase - currExp, exponent, ++base);
    }

    return possibleWays;
}

int powerSum(int X, int N) {
    return powerSumHelper(X, N, 1);
}
