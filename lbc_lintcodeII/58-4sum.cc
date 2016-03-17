/*
题目大意：
给定一个数组，找到所有的4个数的sum 等于target的组合。

解题思路：
见代码

遇到的问题：
没有。
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
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            
            for (int j = i+1; j < nums.size(); ++j) {
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                
                int left = j+1, right = nums.size()-1;
                vector<int> tmp(4);
                tmp[0] = nums[i];
                tmp[1] = nums[j];
                
                while (left < right) {
                    int cur = nums[i] + nums[j] + nums[left] + nums[right];
                    if (cur == target) {
                        tmp[2] = nums[left];
                        tmp[3] = nums[right];
                        ans.push_back(tmp);
                        left++;
                        while (left < right && nums[left] == nums[left-1]) left++;
                    } 
                    else if (cur < target) left++;
                    else right--;
                }
            }
        }
        
        return ans;
    }
};
