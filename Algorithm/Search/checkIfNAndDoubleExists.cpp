#include <vector>
#include <unordered_map>

using namespace std;

struct Element {
    int idx;
    int value;

    Element() {

    }

    Element(int _idx, int _value) {
        this->idx = _idx;
        this->value = _value;
    }
};

class Solution {
    public:
        int checkIfExists(vector<int> &arr) {
            // arr = [10,2,5,3]
            // 
            // N
            // 2N
            // conditions:
            //  i = pointer/index to pointing to one of element in the array
            //  j = pointer/index to pointing to one of element in the array
            // - i != j
            // - arr[i] == 2 * arr[j]
            // - arr[j] == (arr[i] / 2)

            // Basic Idea:
            // 1. Initialize the variables by creating hashmap<int, Element>
            // 2. Iterate over the array:
            //     - Check if one of these conditions is met or not. If met, we can simply break the loop by returning true as a result.
            //       Formula:
            //        1. if map[arr[i] // 2] is exists, it means we found the other element which has a half value from our curr value.
            //        2. if map[2 * arr[i]] it means we found the other element with an exactly 2x bigger than our current element
            //
            //     - Assign a new Element object as a value to our hashmap
            //       map[arr[i]] = Element(i, arr[i]);
            // 3. If we getting out from the loop, means we cannot find any element N and its double.

            unordered_map<int, Element> map;

            for (int i = 0; i < arr.size(); i++) {
                int doubles = arr[i] * 2;
                int halves = arr[i] / 2;

                if (map.find(doubles) != map.end()) {
                    return true;
                }

                if (map.find(halves) != map.end() && arr[i] % 2 == 0) { // We need to make sure the division result does not contain the remainder
                    return true;
                }

                map[arr[i]] = Element(i, arr[i]); 
            }

            // Get our from  loop -> can't find the element
            return false;
        }
};