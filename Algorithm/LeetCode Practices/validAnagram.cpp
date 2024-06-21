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

        bool isValidAnagramUsingArray(std::string s, std::string t) {
            // Check whether the length of both string s and t are same
            // If not, they are not anagram
            if (s.length() != t.length()) {
                return false;
            }

            int *charCount = new int[26]();

            for (char c : s) {
                charCount[c - 'a']++;
            }

            for (char c : t) {
                charCount[c - 'a']--;
            }

            for (int i = 0; i < 26; i++) {
                if (charCount[i] != 0) {
                    return false;
                }
            }

            // Release the memory
            delete[] charCount;

            return true;
        }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << "Is Valid Anagram: " << s.isValidAnagramUsingArray("test", "sett") << std::endl;
    return 0;
}
