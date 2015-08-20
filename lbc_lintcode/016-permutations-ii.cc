/*
题目：23 % 带重复元素的排列 中等

题目大意：
全排列，有重复元素

解题思路：
写好next函数

遇到的问题：
没有太大问题，有了之前一个题目的铺垫，这个题目解决的还算顺利
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        auto len = getPerm(nums);
        ans.push_back(nums);
        for (int i = 1; i < len; ++i) {
            next(nums);
            ans.push_back(nums);
        }
        return ans;
    }
    
    long long getPerm(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans *= i;
        }
        return ans;
    }

    long long getPerm(vector<int> &nums) {
        auto ans = getPerm(nums.size());
        int len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                len++;
            } else {
                ans /= getPerm(len);
                len = 1;
            }
        }
        ans /= getPerm(len);
        return ans;
    }

    void next(vector<int> &nums) {
        int index = nums.size()-1;
        while (index > 0 && nums[index-1] >= nums[index]) --index;
        if (index == 0) {
            reverse(nums, 0, nums.size()-1);
            return;
        }
        int index2 = index;
        while (index2 < nums.size() && nums[index2] > nums[index-1]) ++index2;
        swap(nums[index-1], nums[index2-1]);
        reverse(nums, index, nums.size()-1);
    }

    void reverse(vector<int> &nums, int left, int right) {
        for (int i = left; i < left+(right-left+1)/2; ++i) {
            swap(nums[i], nums[right+left-i]);
        }
    }
};
