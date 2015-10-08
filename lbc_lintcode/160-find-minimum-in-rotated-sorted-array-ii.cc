/*
题目：37 % 寻找旋转排序数组中的最小值 II 中等

题目大意：
给定一个数组，有重复元素。旋转一下，问最小值。

解题思路：
由于有重复数字，所以渐进复杂度是n，所以可以直接遍历了

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int ret = num[0];
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] < ret) {
                ret = num[i];
            }
        }
        return ret;
    }
};
