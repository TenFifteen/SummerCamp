#include <stdio.h>
#include <stdlib.h>

#define N 100
#define max(a, b) ((a) > (b) ? (a) : (b))

/*
 * Problem: Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *          Each element in the array represents your maximum jump length at that position.
 *          Determine if you are able to reach the last index.
 * Solve:   use the method the same with 45 jump game2
 */
int canJump(int* nums, int numsSize)
{
	int jump = 0;
	int range = 0;
	int last = 0;
	int i;
	for (i = 0; i < numsSize-1; ++i) {
		range = max(range, nums[i]+i);
		if (i == last) {
			last = range;
			jump++;
		}
	}

	return last >= numsSize-1;
}

int main()
{
	int nums[N];
	int n;
	while (~scanf("%d", &n)) {
		int i;
		for (i = 0; i < n; ++i) scanf("%d", &nums[i]);
		if (canJump(nums, n)) {
			printf("Can jump!\n");
		} else {
			printf("Cann't jump!\n");
		}
	}

	return 0;
}

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if (n < 1) return true;

        int farJump = nums[0], pos = 1;
        while (farJump < n -1) {
            int nowJump = farJump;
            while (pos <= nowJump) {
                farJump = max(farJump, pos+nums[pos]);
                ++pos;
            }

            if (farJump <= nowJump) return false;
        }

        return true;
    }
};
