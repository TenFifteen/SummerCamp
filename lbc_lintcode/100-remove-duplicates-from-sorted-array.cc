/*
题目：33 % 删除排序数组中的重复数字 容易

题目大意：
给定一个排序的数组，删掉其中重复的数字。要求原地删除。

解题思路：
两个指针

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[cnt-1]) continue;
            nums[cnt++] = nums[i];
        }
        return cnt;
    }
};
