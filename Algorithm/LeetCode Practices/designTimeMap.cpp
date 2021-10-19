#include <list>
#include <string>
#include <unordered_map>

using namespace std;

class TimeStamp {
    private:
        unordered_map<int, unordered_map<string, string> > map;
    public:
        void set(string key, string value, int timestamp) {
            unordered_map<string, string> keyVal = map[timestamp];
            
            keyVal[key] = value;
            map[timestamp] = keyVal;
        }

        string get(string key, int timestamp) {
            int i = timestamp;
            
            while (i > 0) {
                unordered_map<string, string> map2 = map[i];
                if (map2.find(key) != map2.end()) {
                    return map2[key];
                }
                
                i--;
            }
            
            return "";
        }
};
