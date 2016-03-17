/*
题目大意：
给定一个排序的数组，将其中重复的数字删除。

解题思路：
见代码

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return nums.size();
        
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[cnt-1]) continue;
            nums[cnt++] = nums[i];
        }
        
        return cnt;
    }
};