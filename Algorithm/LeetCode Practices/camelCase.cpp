#include <string>
#include <cassert>
using namespace std;

int camelcase(string s) {
    int len = s.length();
    
    assert(len > 0);
    
    int counter = 0;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        if (i == 0) {
            if (islower(c)) counter++;       
        } else { // i > 0
            if (isupper(c)) counter++;
        }
    }
    
    return counter;
}