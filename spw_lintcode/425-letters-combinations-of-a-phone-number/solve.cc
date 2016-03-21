/**
 * Problem: Given a digit string, return all possible letter combinations that the number could represent.
 * Solve: dfs
 * Tips: no
 */
class Solution {
    public:
        void dfs(vector<string> &ans, vector<vector<char>> &chars, string& digits, int pos, string prefix) {
            if (pos == digits.size() && prefix != "") {
                ans.push_back(prefix);
                return;
            }

            int p = digits[pos] - '2';
            if (p < 0) return;
            for (int i = 0; i < chars[p].size(); ++i) {
                dfs(ans, chars, digits, pos+1, prefix+chars[p][i]);
            }
        }

        /**
         * @param digits A digital string
         * @return all posible letter combinations
         */
        vector<string> letterCombinations(string& digits) {
            vector<vector<char>> chars = {
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'}
            };

            vector<string> ans;
            dfs(ans, chars, digits, 0, "");

            return ans;
        }
};
