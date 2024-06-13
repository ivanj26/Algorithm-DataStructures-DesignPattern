#include <string>
#include <vector>
#include <iostream>

uint findMinLength(std::vector<std::string> &strs) {
    size_t minLen = strs.at(0).length();

    for (size_t i = 1; i < strs.size(); i++) {
        size_t currLen = strs[i].length();
        if (minLen > currLen) minLen = currLen;
    } 

    return minLen;
}

std::string longestCommonPrefix(std::vector<std::string> &strs) {
    uint minLength = findMinLength(strs);

    std::string result;
    for (size_t i = 0; i < minLength; i++) {
        bool isValid = true;

        for (size_t j = 1; j < strs.size(); j++) {
            if (strs[j][i] != strs[j-1][i]) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            result.push_back(strs.at(0)[i]);
        } else {
            break;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> v;
    v.push_back("flower");
    v.push_back("flow");
    v.push_back("flight");

    std::cout << "Longest Common Prefix: " << longestCommonPrefix(v) << std::endl;
    return 0;
}
