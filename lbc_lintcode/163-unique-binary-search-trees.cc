/*
题目：32 % 不同的二叉查找树 中等

题目大意：
给定一个n，表示有n个数，问一共有多少种二叉查找树

解题思路：
递推

遇到的问题：
不知道为啥n为0的时候答案还是1
*/
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if (n <= 1) return 1;
        vector<int> ret(n);
        ret[0] = 1;
        for (int i = 1; i < n; ++i) {
            ret[i] = 2 * ret[i-1];
            for (int j = 0; j < i-1; ++j) {
                ret[i] += ret[j] * ret[i-j-2];
            }
        }
        return ret[n-1];
    }
};
