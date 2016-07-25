/**
 * Problem: Given an array with n elements, find the majority numbers whoes count more
 *          than n/2
 * Solve: use a guard, and remember its count.
 * Tips: no
 */
int majorityElement(int* nums, int numsSize) {
	if (numsSize == 0) return 0;

	int tag = nums[0];
	int count = 0;
	int i;
	for (i = 0; i < numsSize; ++i) {
		if (count == 0) {
			tag = nums[i];
			count = 1;
		} else {
			nums[i] == tag ? count++ : count--;
		}
	}
	return tag;
}

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int keeper = 0, cnt = 0;

        for (int n : nums) {
            if (cnt == 0) {
                keeper = n;
                ++cnt;
            } else if (keeper == n) {
                ++cnt;
            } else {
                --cnt;
            }
        }

        return keeper;
    }
};
