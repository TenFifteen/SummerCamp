/*
题目大意：
给定一个数组，把所有0都挪到后边去，其他的数字保持原来的顺序。

解题思路：
见代码。

遇到的问题：
一开始搞错了，搞成两指针了。结果顺序没有保证。
*/
class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        if (nums.size() < 2) return;
        
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[cnt++] = nums[i];
            }
        }
        
        for (int i = cnt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};
