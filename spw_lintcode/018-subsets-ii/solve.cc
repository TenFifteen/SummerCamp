/**
 * Problem: Given a list of numbers that may has duplicate numbers, return all possible subsets
 * Solve: dfs
 * Tips: sort the set in advance
 */
class Solution {
    public:
        /**
         * @param S: A set of numbers.
         * @return: A list of lists. All valid subsets.
         */
        vector<vector<int> > subsetsWithDup(const vector<int> &S) {
            vector<vector<int>> ans;
            vector<int> now;

            vector<int> s(S.begin(), S.end());
            sort(s.begin(), s.end());
            for (int cnt = 0; cnt <= s.size(); ++cnt) {
                dfs(ans, s, now, 0, cnt);
                now.clear();
            }

            return ans;
        }

        void dfs(vector<vector<int>> &ans, const vector<int> &s, vector<int> &now, int pos, int cnt) {
            if (now.size() == cnt) {
                ans.push_back(now);
                return;
            }


            int n = s.size();
            for (int i = pos; i < n; ++i) {
                now.push_back(s[i]);
                dfs(ans, s, now, i+1, cnt);
                now.pop_back();

                while (i+1 < n && s[i+1] == s[i]) ++i;
            }
        }
};

