#include <string>
#include <iostream>

using namespace std;

bool isNotAlnumAndSpace(char c) {
    return !isalnum(c) || c == ' ';
}

void clearNonAlphaNumericAndSpace(string &s) {
    s.erase(
        std::remove_if(
            s.begin(), s.end(), isNotAlnumAndSpace
        ), s.end()
    );
}

void toLower(string &s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
}

bool isPalindrome(string s) {
    clearNonAlphaNumericAndSpace(s);
    toLower(s);

    int length = s.length();
    int halfSize = length / 2;
    for (int i = 0; i < halfSize; i++) {
        int j = length - i - 1;
        if (s[i] != s[j]) {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    cout << isPalindrome("A mam, a") << endl;
    return 0;
}
