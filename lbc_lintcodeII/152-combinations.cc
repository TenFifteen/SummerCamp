/*
题目大意：
给定一个n， 一个k。找到所有从1-n中的k个数的组合。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
    void dfs(vector<vector<int>> &ans, vector<int> &cur, int n, int k, int i) {
        if (n-i+1+cur.size() < k) return;
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        
        cur.push_back(i);
        dfs(ans, cur, n, k, i+1);
        cur.pop_back();
        dfs(ans, cur, n, k, i+1);
    }
    
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, n, k, 1);
        return ans;
    }
};