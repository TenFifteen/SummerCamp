/**
 * Problem: remove the duplicates int the sorted vector
 * Solve: sth like the two sum, when we skip the duplicate
 * Tips: no
 */
int removeDuplicates(int* nums, int numsSize) {
	int i, count = 0;

	for (i = 0; i < numsSize; ++i) {
		nums[count++] = nums[i];
		while (i+1 < numsSize && nums[i+1] == nums[i]) {
			++i;
		}
	}
	return count;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int pos = 0;
        for (int i = 0; i < n; ++i) {
            while (i+1 < n && nums[i+1] == nums[i]) ++i;
            nums[pos++] = nums[i];
        }

        return pos;
    }
};
