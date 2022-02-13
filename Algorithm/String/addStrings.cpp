#include <string>
using namespace std;

class Solution {
    public:
        string addStrings(string num1, string num2) {
            string res;

            int i = num1.size() - 1;
            int j = num2.size() - 1;
            int carry = 0;

            while (i >= 0 && j >= 0) {
                int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
                carry = sum >= 10 ? 1 : 0;

                res.insert(res.begin(), (sum % 10) + '0');

                i--;
                j--;
            }

            while (i >= 0) {
                int sum = (num1[i] - '0') + carry;
                carry = sum >= 10 ? 1 : 0;

                res.insert(res.begin(), (sum % 10) + '0');

                i--;
            }

            while (j >= 0) {
                int sum = carry + (num2[j] - '0');
                carry = sum >= 10 ? 1 : 0;

                res.insert(res.begin(), (sum % 10) + '0');

                j--;
            }

            if (carry > 0) {
                res.insert(res.begin(), '1');
            }

            return res;
        }
};