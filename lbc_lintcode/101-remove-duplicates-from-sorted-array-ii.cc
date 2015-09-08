/*
题目：30 % 删除排序数组中的重复数字 II 容易

题目大意：
给定一个排序的数组，删掉其中重复的数字，每个数字最多留两个

解题思路：
重复的时候记一下数

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
        int cur = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[cnt-1]) {
                if (cur == 1) {
                    cur = 2;
                    nums[cnt++] = nums[i];
                } else {
                    cur = 2;
                    continue;
                }
            } else {
                cur = 1;
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
};
