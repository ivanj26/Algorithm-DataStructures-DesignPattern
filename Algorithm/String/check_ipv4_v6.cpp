#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    private:
        vector<string> split(string q, char sep) {
            vector<string> parts;
            string part;
            stringstream ss(q);
            while (getline(ss, part, sep)) {
                parts.push_back(part);
            }

            return parts;
        }

        bool checkIPv6(string q, char separator = ':') {
            if (count(q.begin(), q.end(), separator) != 7) {
                return false;
            }

            vector<string> parts = split(q, separator);
            if (parts.size() != 8) {
                return false;
            }

            for (string part : parts) {
                if (part.empty() || part.size() > 4) {
                    return false;
                }

                for (char c : part) {
                    if (!(isdigit(c) || (isalpha(c) && toupper(c) <= 'F' && toupper(c) >= 'A'))) {
                        return false;
                    }
                }
            }

            return true;
        }

        bool checkIPv4(string q, char separator = '.') {
            bool isPointExists = q.find(separator) != string::npos;
            if (!isPointExists) {
                return false;
            }
            
            vector<string> parts = split(q, separator);
            if (parts.size() != 4) {
                return false;
            }

            for (string part : parts) {
                if (part.length() > 3 || part.length() == 0 || part.length() > 1 && part[0] == '0') {
                    return false;
                }

                for (char c : part) {
                    if (!isdigit(c)) {
                        return false;
                    }
                }

                if (stoi(part) > 255) {
                    return false;
                }
            }

            return true;
        }

    public:
        string validIPAddress(string q) {
            return checkIPv4(q) ? "IPv4" : (checkIPv6(q) ? "IPv6" : "Neither");
        }
};

int main() {
    string ip;
    cout << "Enter ip address here: ";
    cin >> ip;

    Solution sol;
    cout << "Type of ip address: " << sol.validIPAddress(ip) << endl;
    return 0;
}