/*
题目大意：
给一个n，求出从1-n所可以组成的所有的二分查找二叉树的种类。

解题思路：
递归思想，找到一个根节点，然后分别求两边的种类 ，然后相乘。

遇到的问题：
一次通过。
*/
class Solution {
public:
    int numTrees(int n) {
        if(n <= 0)return 0;
        vector<int> ans(n+1);
        ans[0] = 1;
        ans[1] = 1;
        for(int i = 2; i <= n; ++i){
            int sum = 0;
            for(int j = 0; j < i; ++j){
                sum += ans[j]*ans[i-j-1];
            }
            ans[i] = sum;
        }
        return ans[n];
    }
};