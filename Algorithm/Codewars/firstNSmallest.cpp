#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> firstNSmallest(const std::vector<int> &arr, int n) {
    if (n == 0) {
        return {};
    }
    
    std::vector<std::pair<int, int>> sorted(arr.size());
    
    for (size_t i = 0; i < arr.size(); i++) {
        sorted[i] = std::make_pair(arr[i], i);
    }

    // Sort by key
    // If key is equal, compare with its values.
    std::sort(sorted.begin(), sorted.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
        if (p1.first < p2.first) {
            return true;
        } else if (p1.first == p2.first) {
            return p1.second < p2.second;
        } else {
            return false;
        }
    });

    sorted.resize(n);

    // Sort by value (In this case: sort by index)
    std::sort(sorted.begin(), sorted.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
        return p1.second < p2.second;
    });

    std::vector<int> out;
    for (size_t i = 0; i < sorted.size(); i++) {
        out.push_back(sorted[i].first);
    }

    return out;
}