#include <vector>
#include <climits>

std::vector<int> remove_values(std::vector<int> integers, std::vector<int> values) {
  for (size_t i = 0; i < values.size(); i++) {
    int val = values[i];
    
    for (size_t j = 0; j < integers.size(); j++) {
      if (integers[j] == val) {
        integers.erase(integers.begin() + j);
        j--;
      }
    }
    
  }
  
  return integers;
}