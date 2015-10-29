/*
题目：23 % 用递归打印数字 中等

题目大意：
用递归的方式打印从1到n位所有的数字。

解题思路：
递归

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> ans;
        if (n < 1) return ans;
        if (n == 1) {
            for (int i = 1; i < 10; ++i) {
                ans.push_back(i);
            }
            return ans;
        }
        
        auto ret = numbersByRecursion(n-1);
        int left = 1;
        int right = 10;
        for (int i = 0; i < n-1; ++i) {
            left *= 10;
            right *= 10;
        }
        for (int i = left; i < right; ++i) {
            ret.push_back(i);
        }
        
        return ret;
    }
};
