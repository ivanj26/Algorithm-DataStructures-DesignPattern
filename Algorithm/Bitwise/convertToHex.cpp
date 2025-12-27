#include <vector>
#include <string>
#include <sstream>

using namespace std;
{
    class Solution {
        public:
            string toHex(int num) {
                unsigned int uNum = num; // num = 26, uNum = 26

                // Char Collection of hexadecimal
                // 0-9,a-f
                vector<char> v = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
                stringstream ss;

                do {
                    ss << v[uNum % 16]; // 1%16 1st: 10, 2nd: 1
                    uNum = uNum / 16;
                } while (uNum > 0);

                string result = ss.str();
                return {result.rbegin(), result.rend()};
            }
    }
}