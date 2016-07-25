#include <stdio.h>

#define N 100

/**
 * Problem: Given an array of integers, every element appears three times except for one
 *          Find the single one.
 * Solve: use variable ones to represent bit '1', twos to represent bit '2', then we simulate
 *        bitwise XOR of ternary.
 * Tips: see below
 */
int singleNumber(int* nums, int numsSize) {
	int ans = 0;
	int i;
	int ones = 0, twos = 0;
	for (i = 0; i < numsSize; ++i) {
		int temp = ones;
		// 1 + 0 = 1
		ones ^= nums[i];

		// 1 + 1 = 2
		twos = twos ^ (temp & nums[i]);

		// 11 -> 00. 3 -> 0
		int clear = twos & ones;
		ones = clear ^ ones;
		twos = clear ^ twos;
	}

	return ones;
}

int main()
{
	int n, i;
	int arr[N];
	while (~scanf("%d", &n)) {
		for (i = 0; i < n; ++i)	 {
			scanf("%d", &arr[i]);
		}

		printf("The single number is %d\n", singleNumber(arr, n));
	}

	return 0;
}

/**
 * think every number was represented by binary form
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int n : nums) {
            int aside = n & ones;
            ones = ones ^ n;

            twos = aside ^ twos;

            int mask = ones & twos;
            ones ^= mask;
            twos ^= mask;
        }

        return ones;
    }
};
