/**
 * Problem: Given n pairs of parentheses, write a function to
 *          generate all combinations of well-formed parentheses.
 * Solve: dfs + left/right brackets.
 * Tips: no
 */
class Solution {
    public:
        void dfs(vector<string> &ans, int left, int right, string prefix) {
            if (left == 0 && right == 0) {
                ans.push_back(prefix);
                return;
            }

            if (left > 0) {
                dfs(ans, left-1, right+1, prefix+'(');
            }

            if (right > 0) {
                dfs(ans, left, right-1, prefix+')');
            }
        }
        /**
         * @param n n pairs
         * @return All combinations of well-formed parentheses
         */
        vector<string> generateParenthesis(int n) {
            // Write your code here
            vector<string> ans;

            dfs(ans, n, 0, "");

            return ans;
        }
};
