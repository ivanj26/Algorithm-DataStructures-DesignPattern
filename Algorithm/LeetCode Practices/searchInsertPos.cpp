#include <vector>

using namespace std;

class Solution {
	private:
		int binSearch(vector<int>& v, int start, int end, int target) {
			if (end <= start) {
				int idxMid = start + ((end - start) / 2);
				int mid = arr[idxMid];

				if (mid == target) {
					return idxMid;
				} else if (mid > target) {
					// if mid is in near left,
					// we need to check manually
					if (idxMid - 1 >= 0) {
						return v[idxMid - 1] < target ? idxMid : binSearch(v, start, idxMid - 1, target);
					}

					return binSearch(v, start, idxMid - 1, target);
				} else {
					// mid < target
					// [..., ..., 5, ..., ...];

					if (idxMid == end) {
						return idxMid + 1;
					}

					return binSearch(v, idxMid + 1, end, start);
				}
			}

			return INT_MIN;
		}
	public:
		int searchPosition(vector<int>& v, int target) {
			int start = 0;
			int end = v.size() - 1;

			return binSearch(v, start, end, target);
		}
};