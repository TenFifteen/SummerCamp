/*
题目大意：
给定一个数组，将其中的0都移到最后去，但是要保持其他数字的相对位置。

解题思路：
见代码

遇到的问题：
没有问题。

再次阅读：
非常简单，扫一遍就行。
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        while (index < nums.size()) {
            nums[index++] = 0;
        }
    }
};