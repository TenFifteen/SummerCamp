/*
题目：30 % 打劫房屋 中等

题目大意：
给定一个数组，表示一排房子的每个的存放的钱数。要求不能抢劫相邻的两个房子。问总共
最多可以抢劫多少钱？

解题思路：
动态规划。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if (A.size() == 0) return 0;
        if (A.size() == 1) return A[0];
        if (A.size() == 2) return max(A[0], A[1]);
        
        long long a = A[0], b = max(A[0], A[1]);
        for (int i = 2; i < A.size(); ++i) {
            long long cur = max(a + A[i], b);
            a = b;
            b = cur;
        }
        
        return b;
    }
};
