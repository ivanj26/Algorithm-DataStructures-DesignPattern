#include <vector>
#include <iostream>

using namespace std;

void print(vector<int> &arr) {
	for (auto a : arr) {
		cout << a << " ";
	}
	cout << endl;
}

class MergeSort {
	private:
		static void merge(vector<int> &arr, int left, int middle, int right)
		{
			vector<int> sorted;
			int i, j;

			for (i = left, j = middle; i < middle && j < right;) {
				if (arr[i] > arr[j]) {
					sorted.push_back(arr[j]);
					j++;
				} else {
					sorted.push_back(arr[i]);
					i++;
				}
			}

			while (i < middle) {
				sorted.push_back(arr[i]);
				i++;
			}

			while (j < right) {
				sorted.push_back(arr[j]);
				j++;
			}

			for (i = left; i < right; i++) {
				arr[i] = sorted[i - left];
			}
		}

		static void split(vector<int> &arr, int left, int right)
		{
			if (right - left < 2) {
				return;
			}

			int middle = (left + right) / 2;
			split(arr, left, middle);
			split(arr, middle, right);

			merge(arr, left, middle, right);
		}
	public:
		static void mergeSort(vector<int> &arr)
		{
			split(arr, 0, arr.size());
		}
};

int main(int argc, char const *argv[])
{
	vector<int> vec = {3, 4, 7, 2, 1, 10, 9};
	MergeSort::mergeSort(vec);

	print(vec);
	return 0;
}
