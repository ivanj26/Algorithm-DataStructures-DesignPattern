#include <iostream>
#include <string>
#include <map>
using namespace std;

#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'

struct Math {
    int sign;
    int pow;
    int coeff;
    Math() {
        sign = 1;
        pow = 0;
        coeff = 0;
    }
};

bool sortByHighestPower(const Math &a, const Math &b) {
    return a.pow > b.pow; // Highest power first
}

string getStringInBracket(string str, int start = 0) {
    int end = str.find(OPEN_BRACKET, start);
    start = end + 1;

    end = str.find(CLOSE_BRACKET, start);
    string s = str.substr(start, end - start);

    return s;
}

vector<Math> parsePolynomialStr(string s) {
    vector<Math> res;
    int i = 0;

    int n = s.length();
    while (i < n) {
        int sign = 1;
        int pow;
        int coeff = 0;

        // check sign
        if (s[i] == '-' || s[i] == '+') {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }

        // check the digits here
        while (i < n && isdigit(s[i])) {
            coeff = (coeff * 10) + (s[i] - '0');
            i++;
        }

        bool hasVariable = false;
        if (i < n && isalpha(s[i])) { // if has variable
            // Handle power value
            hasVariable = true;
            i++;

            if (s[i] == '^') {
                i++;

                int powSign = 1;
                if (s[i] == '-') {
                    powSign = -1;
                    i++;
                }

                int expValue = 0;
                while (i < n && isdigit(s[i])) {
                    expValue = (expValue * 10) + (s[i] - '0');
                    i++;
                }

                pow = powSign == -1 ? -expValue : expValue;
            } else {
                pow = 1;
            }
        }

        if (!hasVariable) {
            pow = 0;
        }

        Math m;
        m.pow = pow;
        m.coeff = coeff;
        m.sign = sign;

        res.push_back(m);
    }

    return res;
}

vector<Math> multiplyPoly(vector<Math> &v1, vector<Math> &v2) {
    map<int, int> resultMp;
    for (auto &t1 : v1) {
        for (auto &t2 : v2) {
            int newCoeff = t1.coeff * t2.coeff;
            int newPow = t1.pow + t2.pow;

            resultMp[newPow] += (newCoeff * t1.sign * t2.sign);
        }
    }

    vector<Math> result;
    for (map<int, int>::const_iterator it = resultMp.begin(); it != resultMp.end(); ++it) {
        int exp = it->first;
        int coef = it->second;

        if (coef != 0) {
            Math m;
            m.pow = exp;
            m.coeff = coef < 0 ? -coef : coef;
            m.sign = coef < 0 ? -1 : 1;

            result.push_back(m);
        }
    }

    // Sort by power in descending order
    sort(result.begin(), result.end(), sortByHighestPower);

    return result;
}

void printVec(vector<Math> v) {
    for (auto u : v) {
        cout << u.sign << " " << u.coeff << " " << u.pow << endl; 
    }
}

string polyNomToString(vector<Math> &v) {
    if (v.empty()) return "0";

    string result;
    for (const auto &t : v) {
        if (t.sign < 0) {
            result += "-";
        }

        if (t.sign > 0 && !result.empty()) {
            result += "+";
        }

        result += to_string(t.coeff);
        if (t.pow != 0) {
            result += "x^" + to_string(t.pow);
        }
    }

    return result;
}

void calculate(string str) {
    string s1 = getStringInBracket(str, 0);
    string s2 = getStringInBracket(str, str.find(CLOSE_BRACKET));

    vector<Math> v1 = parsePolynomialStr(s1);
    vector<Math> v2 = parsePolynomialStr(s2);

    vector<Math> multiplied = multiplyPoly(v1, v2);
    cout << polyNomToString(multiplied) << endl;
}

int main() {
    string str;
    getline(cin, str);

    calculate(str);

    return 0;
}