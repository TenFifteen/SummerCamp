/*
题目大意：
给n个数，问可以形成多少个不同的BST

解题思路：
动规。其实就是卡塔兰数

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        vector<int> ans(n+1, 1);
        for (int i = 2; i <= n; ++i) {
            ans[i] = ans[i-1]*2;
            for (int j = 1; j <= i-2; ++j) {
                ans[i] += ans[j] * ans[i-j-1];
            }
        }
        
        return ans[n];
    }
};
