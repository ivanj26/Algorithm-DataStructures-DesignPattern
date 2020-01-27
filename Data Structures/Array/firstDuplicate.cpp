#include <vector>
#include <iostream>

/**
 * Input range: 1 <= length <= 10^5
 * Input elmt : 1 <= arr[i] <= length
 **/
int firstDuplicate(std::vector<int> vec) {
    int keys[100000] = {0};

    for (auto el : vec)
    {
        if ((++keys[el-1]) > 1) {
            return el; 
        }
    }

    return -1;
}

int main(int argc, const char** argv) {
    std::vector<int> vec{10, 1, 2, 4, 5, 9, 4};
    int duplicatedElmt = firstDuplicate(vec);

    if (duplicatedElmt > -1) std::cout << "Found duplicate: " << duplicatedElmt << std::endl;
    else std::cout << "Not found!" << std::endl;

    return 0;
}