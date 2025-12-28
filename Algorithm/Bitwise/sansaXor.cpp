#include <vector>
using namespace std;

int sansaXor(vector<int> arr) {
    if ((arr.size() & 1) == 0) {
        return 0;
    } 
    
    int result = 0;
    for (int i = 0; i < arr.size(); i += 2) {
        result ^= arr[i];
    }
    
    return result;
}
