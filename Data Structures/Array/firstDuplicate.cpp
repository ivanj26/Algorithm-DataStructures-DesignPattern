#include <vector>

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
    return 0;
}