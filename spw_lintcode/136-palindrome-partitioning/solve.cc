/**
 * Problem: Given a string s, partition s such that every substring of the partition is a palindrome.
 *          Return all possible palindrome partitioning of s.
 * Solve: plain judgement + dfs
 * Tips: no
 */
class Solution {
    public:
        bool isPalindrome(string &s) {
            int l = 0, r = s.size() - 1;

            while (l < r) {
                if (s[l] != s[r]) return false;
                else {
                    ++l; --r;
                }
            }
            return true;
        }

        void dfs(vector<vector<string>> &ans, string &s, int pos, vector<string> &now) {
            if (pos == s.size()) {
                ans.push_back(now);
                return;
            }

            string ss;
            for (int i = pos; i < s.size(); ++i) {
                ss += s[i];
                if (isPalindrome(ss)) {
                    now.push_back(ss);
                    dfs(ans, s, i+1, now);
                    now.pop_back();
                }
            }
        }
        /**
         * @param s: A string
         * @return: A list of lists of string
         */
        vector<vector<string>> partition(string s) {
            // write your code here
            vector<vector<string>> ans;
            vector<string> now;
            dfs(ans, s, 0, now);

            return ans;
        }
};
