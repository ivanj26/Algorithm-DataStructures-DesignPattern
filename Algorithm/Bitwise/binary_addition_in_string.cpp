#include <iostream>

using namespace std;

bool validateValidBinary(string &s) {
    int i = 0;
    while (i < s.length()) {
        int c = s[i] - '0';
        if (!(c == 0 || c == 1)) {
            return false;
        }

        i++;
    }

    return true;
}

string addTwoBinary(string &a, string &b) {
    int i = a.size() - 1;
    int j = b.size() - 1;

    int carry = 0;
    string result;
    while (i >= 0 && j >= 0) {
        int sum = (a[i] - '0') + (b[j] - '0') + carry;

        if (carry > 0) {
            carry -= 1;
        }

        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }

        result.push_back(sum + '0');

        i--;
        j--;
    }

    if (i >= 0) {
        int sum = (a[i] - '0') + carry;

        if (carry > 0) {
            carry -= 1;
        }

        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }

        result.push_back(sum + '0');

        i--;
    }

    if (j >= 0) {
        int sum = (b[j] - '0') + carry;

        if (carry > 0) {
            carry -= 1;
        }

        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }

        result.push_back(sum + '0');

        j--;
    }

    if (carry > 0) {
        result.push_back(carry + '0');
    }

    int len = result.length();
    int divider = 8;

    while (len / divider > 0) {
        divider += 8;
    }

    int remainder = divider - len;
    int k = 1;
    while (k <= remainder) {
        result.push_back(0 + '0');
        k++;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

int main() {
    string bin1;
    getline(cin, bin1);

    // Validate if it is valid binary
    bool isValid = validateValidBinary(bin1);
    if (!isValid) {
        cout << "Invalid binary number!" << endl;
        return -1;
    }

    string bin2;
    getline(cin, bin2);

    // Validate if it is valid binary
    isValid = validateValidBinary(bin2);
    if (!isValid) {
        cout << "Invalid binary number!" << endl;
        return -1;
    }

    string result;
    result = addTwoBinary(bin1, bin2);

    cout << result << endl;
}