/**
 * Problem: given an array, find the max sum of the non-adjacent
 *          element(which is non-negative).
 * Solve: something like knapsack, because the elements can't be negative
 *        we just keep two variable, the maximum sum end of the previous
 *        previous element and end of the previous element.
 * Tips: no
 */
#define max(a, b) ((a) > (b) ? (a) : (b))
int rob(int* nums, int numsSize) {
	int i;
	int pre1 = 0, pre2 = 0;
	for (i = 0; i < numsSize; ++i) {
		if (i % 2 == 0) {
			pre1 = max(pre1+nums[i], pre2);
		} else {
			pre2 = max(pre2+nums[i], pre1);
		}
	}

	return max(pre1, pre2);
}

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        for (int n : nums) {
            int now = max(n+prev2, prev1);
            prev2 = prev1;
            prev1 = now;
        }

        return prev1;
    }
};
