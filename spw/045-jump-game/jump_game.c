#include <stdio.h>
#include <stdlib.h>

#define N 100
#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX_INT (0x7FFFFFFF)

int jump1(int* nums, int numsSize)
{
	int dp[N];
	int i;
	for (i = 0; i < numsSize; ++i) dp[i] = MAX_INT;
	dp[0] = 0;
	for (i = 0; i < numsSize; ++i) {
		int j;
		for (j = 1; j <= nums[i]; ++j) {
			if (i + j == numsSize) break;
			dp[i+j] = min(dp[i+j], dp[i]+1);
		}
	}

	return dp[numsSize-1];
}

/**
 * Problem: Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *          Each element in the array represents your maximum jump length at that position.
 *          Your goal is to reach the last index in the minimum number of jumps.
 * Solve: simple dp: TLE.
 *        copy from the discuss board which gain the most votes.
 *        1. When we in the first place, nums[0] tell us how far we can go. Within this range, we can see in which
 *           place we can go the furthest. Remember this distance(now_range). When we step out of the range specified
 *           by nums[0], we should add the 'step' by one and get the next range(now_range)
 *        2. because we must step in one place of the range, then we must add 'step' by one before we go out of it.
 *           We have many choice in this range, of course, we will choose the one in which we can go the furtheset.
 *        3. That is the so called greedy.
 * Tips: In fact, we don't care about how nums[n-1] is
 */
int jump(int* nums, int numsSize)
{
	int last = 0;
	int now_range = 0;
	int step = 0;

	int i;
	// consider the boundary, of coure we add step by 1 at first.
	// Think about the extreme case: nums[0] >= numsSize-1, then the step = 1. When nums[0] = numsSize - 1, if we want to
	// get it right, we shouldn't consider the nums[numsSize-1], or we'll get answer : 2. Think it further, we don't care
	// what nums[numsSize-1] is because we'll never go futher.
	// Think about the other extreme case, numsSize = 1, then step = 1, that is, as long as numsSize > 1, we have to take
	// a step at least.
	for (i = 0; i < numsSize-1; ++i) {
		now_range = max(now_range, i+nums[i]);
		if (i == last) {
			last = now_range;
			step++;
		}
	}

	return step;
}

int main()
{
	int n;
	int arr[N];
	while (~scanf("%d", &n)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		int jump_count = jump(arr, n);
		printf("We need %d jump\n", jump_count);
	}

	return 0;
}

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int i = 1, step = 1, longJump = nums[0];
        while (longJump < n-1) {
            int nowJump = i;
            while (i <= longJump) {
                nowJump = max(nowJump, nums[i] + i);
                ++i;
            }
            longJump = nowJump;
            ++step;
        }

        return step;
    }
};
