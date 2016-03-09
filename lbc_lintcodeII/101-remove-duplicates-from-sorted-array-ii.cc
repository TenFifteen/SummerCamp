/*
题目大意：
给定一个排序的数组，将其中重复数量大于2的数字的多余的部分去掉。

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
        if (nums.size() < 3) return nums.size();
        
        int last = nums[0], cnt = 1, total = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == last) {
                cnt++;
                if (cnt < 3) nums[total++] = nums[i];
            } else {
                cnt = 1;
                last = nums[i];
                nums[total++] = nums[i];
            }
        }
        
        return total;
    }
};