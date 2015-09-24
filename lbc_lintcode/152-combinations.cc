/*
题目：32 % 组合 中等

题目大意：
给定一个n和k。问所有的1-n的k各数的组合

解题思路：
回溯

遇到的问题：
忘记了return了。
*/
class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int>> ans;
        vector<int> now;
        sub(ans, 1, n, k, now);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, int cur, int n, int k, vector<int> &now) {
        if (k == 0) {
            ans.push_back(now);
            return;
        }
        if (cur > n) return;
        now.push_back(cur);
        sub(ans, cur+1, n, k-1, now);
        now.pop_back();
        sub(ans, cur+1, n, k, now);
    }
};
