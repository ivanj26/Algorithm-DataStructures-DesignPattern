#include <string>
#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;

class LRUCache {
    private:
        unsigned int limitSize = 0;
        unordered_map<string, list<pair<string, int>>::iterator> mp;
        list<pair<string, int>> cacheList;
    public:
        LRUCache(int maxSize) {
            limitSize = maxSize;
        }

        int get(string key) {
            if (mp.find(key) == mp.end()) {
                return -1;
            }

            auto iter = mp[key];
            cacheList.splice(cacheList.begin(), cacheList, iter);

            return cacheList.front().second;
        }

        bool has(string key) {
            if (mp.find(key) == mp.end()) {
                return false;
            }

            auto it = mp[key];
            cacheList.splice(cacheList.begin(), cacheList, it);

            return true;
        }

        void put(string key, int value) {
            if (mp.find(key) == mp.end()) {
                int currSize = mp.size();
                if (currSize >= limitSize) {
                    auto it = cacheList.back();
                    mp.erase(it.first);
                    cacheList.pop_back();
                }

                pair<string, int> p = make_pair(key, value);
                
                cacheList.push_front(p);
                mp[key] = cacheList.begin();
            } else {
                // Move the item to front of list
                list<pair<string, int>>::iterator it = mp[key];
                it->second = value;

                cacheList.splice(cacheList.begin(), cacheList, it);
            }
        }
};

int main() {
    LRUCache cache(10);

    cache.put("1", 1);
    cache.put("1", 2);

    cout << cache.get("1") << endl;

    return 0;
}