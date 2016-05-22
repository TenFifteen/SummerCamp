/**
 * Problem: Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 *          Note: The input string may contain letters other than the parentheses ( and  ).
 *          Examples:
 *          "()())()" -> ["()()()", "(())()"]
 *          "(a)())()" -> ["(a)()()", "(a())()"]
 *          ")(" -> [""]")"
 * Solve: dfs(select or not for each parenthes)
 * Tips: see comments below.
 */
class Solution {
    public:
        vector<string> removeInvalidParentheses(string s) {
            int left = 0, legal = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '(') ++left;
                else if (s[i] == ')') {
                    if (left > 0) {
                        legal += 2;
                        --left;
                    }
                }
            }

            // the max character we could to delete(include character)
            int diff = s.size()-legal;
            set<string> ans;
            string now;
            dfs(ans, s, now, 0, 0, 0, diff);

            vector<string> res;
            for (string ss : ans) {
                res.push_back(ss);
            }

            if (res.size() == 0) res.push_back("");
            return res;
        }

        void dfs(set<string> &ans, string s, string now, int i, int left, int right, int diff) {
            if (i == s.size()) {
                if (left == right && now != "")
                    ans.insert(now);
                return;
            }

            // i is the now length, and left+right is the now parentheses
            if (left < right || i-(left+right) > diff) return;

            if (s[i] == '(' || s[i] == ')') {
                if (s[i] == '(')  dfs(ans, s, now+s[i], i+1, left+1, right, diff);
                else              dfs(ans, s, now+s[i], i+1, left, right+1, diff);

                dfs(ans, s, now, i+1, left, right, diff);
            } else {
                dfs(ans, s, now+s[i], i+1, left, right, diff);
            }
        }
};
