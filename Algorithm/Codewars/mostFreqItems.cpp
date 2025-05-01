#include <vector>
#include <unordered_map>

unsigned int most_frequent_item_count(const std::vector<int>& collection) {
  if (collection.size() == 0) {
    return 0;
  }
  
  std::unordered_map<int, std::pair<int, int>> mp;
  for (int num : collection) {
    if (mp.find(num) == mp.end()) {
      mp[num] = {num, 1};
    } else {
      mp[num].second++;
    }
  }
  
  std::vector<std::pair<int, int>> vec;
  for (auto kv : mp) {
    vec.push_back(kv.second);
  }
  
  std::sort(vec.begin(), vec.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
    return p1.second > p2.second;
  });
  
  return vec[0].second;
}