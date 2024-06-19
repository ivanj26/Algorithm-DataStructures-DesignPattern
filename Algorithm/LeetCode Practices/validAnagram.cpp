#include <map>
#include <string.h>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool isValidAnagram(std::string s, std::string t) {
            std::map<char, int> m;

            for (char c : s) {
                if (m.find(c) == m.end()) {
                    m[c] = 1;
                } else {
                    m[c]++;
                }
            }

            for (char c : t) {
                bool isFound = m.find(c) != m.end();
                if (isFound) {
                    if (--m[c] == 0) {
                        m.erase(c);
                    }
                } else {
                    return false;
                }
            }

            return true;
        }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << "Is Valid Anagram: " << s.isValidAnagram("test", "sett") << std::endl;
    return 0;
}
