/**
 * @file missingNumber.cpp
 * @author Ivan Jonathan
 * @brief You are supposed to label a bunch of boxes with numbers from 0 to n
 * 	      and all the labels are stored in the array arr. Unfortunately one of the labels is missing.
 * 		  Your task is to find it.
 * @version 0.1
 * @date 2022-01-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>

using namespace std;

int missingNumber(vector<int> nums) {
	// [3, 0, 2], missing number = 1

	// solution:
	// sum number using arithmetic formula
	// 0 + 1 + 2 + 3 + ... + n
	// Formula 	: ((n / 2) * (2a + Un)
	//			  ((n / 2) * (2a + (n - 1) b))
	// a = 1st term
	// n = total number of terms
	// b = common difference between the terms

	int n = nums.size();

	// using float data-type to avoid auto-conversion
	float m = float(n) / 2;
	float sum = m * (2 + (n - 1));

	for (int i = 0; i < n; i++) {
		sum -= nums[i];
	}

	return int(sum);
}