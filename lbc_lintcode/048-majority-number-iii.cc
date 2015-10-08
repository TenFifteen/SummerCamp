/*
题目：25 % 主元素 III 中等

题目大意：
给定一个数组，其中某个元素的数量超过了所有元素数量的k分之一，找出该元素

解题思路：
二分

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        int ans = 0;
        auto ret = sub(nums, 0, nums.size()-1, k);
        for (auto r : ret) ans = r;
        return ans;
    }
    
    unordered_set<int> sub(vector<int> &nums, int left, int right, int k) {
        unordered_set<int> ans;
        if (left > right) return ans;
        if (left == right) {
            ans.insert(nums[left]);
            return ans;
        }
        
        int mid = left + (right-left+1)/2;
        auto ret_l = sub(nums, left, mid-1, k);
        auto ret_r = sub(nums, mid, right, k);
        for (auto r : ret_l) {
            if (count(nums, left, right, r) > (right-left+1)/k) ans.insert(r);
        }
        for (auto r : ret_r) {
            if (ans.find(r) != ans.end()) continue;
            if (count(nums, left, right, r) > (right-left+1)/k) ans.insert(r);
        }
        return ans;
    }
    
    int count(vector<int> &nums, int left, int right, int val) {
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            if (nums[i] == val) ret++;
        }
        return ret;
    }
};

