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
/*
第二次做：
一开始还以为发现了两种解法呢，一种是left，right交换的那种；另一种就是现在这种。
不过后来发现人家要求保持顺序的。
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = 0;
        for (auto n : nums) {
            if (n != 0) nums[len++] = n;
        }
        
        for (int i = len; i < nums.size(); ++i) nums[i] = 0;
    }
};