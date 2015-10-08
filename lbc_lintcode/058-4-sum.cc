/*
题目：19 % 四数之和 中等

题目大意：
给定一个无序数组，有重复元素，求出所有不重复的四个数，其和为target

解题思路：
跟3-sum是一样的，只不过这次要多加一层

遇到的问题：
其实我在想，好像可以将其降低到n*n的复杂度啊。
先将nums预处理成所有数字的两两的和，然后运行一遍2-sum不就行了么，
就是去重不太好弄。空间复杂度也会上升。
*/
class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-3; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < nums.size()-2; ++j) {
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = nums.size()-1;
                while (left < right) {
                    int cur = nums[i] + nums[j] + nums[left] + nums[right];
                    if (cur == target) {
                        vector<int> tmp(4);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[left];
                        tmp[3] = nums[right];
                        ans.push_back(tmp);
                        while (left < right && nums[left+1] == nums[left]) ++left;
                        while (left < right && nums[right-1] == nums[right]) --right;
                        left++;
                        right--;
                    } else if (cur < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

