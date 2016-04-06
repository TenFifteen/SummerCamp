/**
 * Problem: Given an array nums containing n + 1 integers where each integer is
 *          between 1 and n (inclusive), prove that at least one duplicate number
 *          must exist. Assume that there is only one duplicate number, find the duplicate one.
 * Solve: place the i below to 1~n to the index i.
 * Tips: the duplicates number may repeat more than once
 */
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int n = nums.size();

            for (int i = 0; i < n; ++i) {
                while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1])
                    swap(nums[i], nums[nums[i]-1]);
            }

            for (int i = 0; i < n; ++i) {
                if (nums[i] != i+1)
                    return nums[i];
            }
        }
};
