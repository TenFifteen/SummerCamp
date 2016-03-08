/*
题目大意：
给定n对括号，生成所有满足要求的括号。

解题思路：
dfs

遇到的问题：
没有。
*/
class Solution {
    void dfs(vector<string> &ans, string now, int left, int right) {
        if (right == 0) {
            ans.push_back(now);
            return;
        }
        
        if (left > 0) dfs(ans, now+"(", left-1, right);
        if (right > left) dfs(ans, now+")", left, right-1);
    }
    
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> ans;
        dfs(ans, "", n, n);
        return ans;
    }
};