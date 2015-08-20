/*
题目：全排列 中等

题目大意：
给定一个数组，无重复，求其全排列。非递归

解题思路：
使用nextPermutation函数，求下一个排列

遇到的问题：
next中，一开始将后面降序序列中的第一个与index-1的元素交换了，应该是交换大于
index-1元素的最小的元素


*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        auto len = perm(nums.size());
        for (long long i = 1; i < len; ++i) {
            getNext(nums);
            ans.push_back(nums);
        }
        return ans;
    }

    void getNext(vector<int> &nums) {
        int index = nums.size()-1;
        while (index > 0 && nums[index-1] > nums[index]) index--;
        if (index == 0) {
            reverse(nums, 0, nums.size()-1);
            return;
        }
        int index2 = index;
        while (index2 < nums.size() && nums[index2] > nums[index-1]) {
            index2++;
        }
        swap(nums[index-1], nums[index2-1]);
        reverse(nums, index, nums.size()-1);
    }
    
    void reverse(vector<int> &nums, int left, int right) {
        for (int i = left; i < left+(right-left+1)/2; ++i) {
            swap(nums[i], nums[right+left-i]);
        }
    }

    long long perm(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans *= i;
        }
        return ans;
    }
};

