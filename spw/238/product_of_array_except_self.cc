/**
 * Problem: Given an array of n integers where n > 1, nums, return
 *          an array output such that output[i] is equal to the
 *          product of all the elements of nums except nums[i].
 * Solve: two pointers(Memorize the accumulate product from each side.).
 * Tips: no
 */
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n, 1);

            int left_acc_product = 1;
            int right_acc_product = 1;

            for (int i = 0; i < n; ++i) {
                ans[i] *= left_acc_product;
                ans[n-1-i] *= right_acc_product;

                left_acc_product *= nums[i];
                right_acc_product *= nums[n-1-i];

            }

            return ans;

        }

};
