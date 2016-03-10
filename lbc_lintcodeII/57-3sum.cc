/*
题目大意：
给定一个数组，问其中有多少个三个元素的和是0，将其全部输出来。

解题思路：
排序后，遍历第一个元素，卡尺法找后两个元素。

遇到的问题：
没有。
*/
class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                int cur = nums[i] + nums[left] + nums[right];
                if (cur == 0) {
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    ans.push_back(tmp);
                    
                    left++;
                    while (left < right && nums[left] == nums[left-1]) left++;
                } 
                else if (cur > 0) right--;
                else left++;
            }
        }
        
        return ans;
    }
};
