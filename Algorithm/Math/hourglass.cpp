#include <vector>

int hourglass(std::vector< std::vector<int> > arr)
{
	int width = arr[0].size();
	int height = arr.size();
	std::vector<long> sums;

	//        j=0, j=1, j=2
	// i = 0 | 1 1 1 0 0 0
	// i = 1 | 0 1 0 0 0 0
	// i = 2 | 1 1 1 0 0 0

	for (int i = 0; i < height - 2; i++) {
		for (int j = 0; j < width - 2; j++) {
			int s = 0;

			// add top and bottom lines in this inner loop
			for (int k = 0; k < 3; k++) {
				s += arr[i][j+k];
				s += arr[i+2][j+k];
			}

			// add middle element
			s += arr[i+1][j+1];

			sums.push_back(s);
		}
	}

	return *max_element(sums.begin(), sums.end());
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
