#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief transform integer into roman characters.
 * I = 1
 * V = 5
 * X = 10
 * L = 50
 * C = 100
 * D = 500
 * M = 1000
 * 
 * compile: g++ -std=c++11 intToRoman.cpp
 * 
 * @param num 
 * @return string 
 */
void intToRoman(int num) {
    vector<int> v = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string str[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    int div = 0;
    string res = "";

    while (num > 0) {
        div = num / v[i];
        num = num % v[i];

        while (div--) {
            res += str[i];
        }

        i--;
    }

    cout << res << endl;
};

int main(int argc, char const *argv[])
{
    intToRoman(499);
    return 0;
}
