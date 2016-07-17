/**
 * Problem: Given a string s1, we may represent it as a binary tree by partitioning
 *          it to two non-empty substrings recursively.
 * Solve: recursive and cut branches
 * Tips: no
 */
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        if (s1.size() == 1 && s1 == s2) return true;

        string t1(s1), t2(s2);
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;

        int n = s1.size();
        for (int i = 1; i < n; ++i) {
            string l1 = s1.substr(0, i), r1 = s1.substr(i);
            string l2 = s2.substr(0, n-i), r2 = s2.substr(n-i);

            if (isScramble(l1, r2) && isScramble(r1, l2) || isScramble(l1, s2.substr(0, i)) && isScramble(r1, s2.substr(i)))
                return true;
        }

        return false;
    }
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        string t1(s1), t2(s2);
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;

        int n = s1.size();
        vector<bool> r(n+1, false);
        vector<vector<bool>> tr(n, r);
        vector<vector<vector<bool>>> dp(n, tr);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][0] = true;
                dp[i][j][1] = s1[i] == s2[j];
            }
        }

        // i iterator to n-len
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n-len; ++i) {
                for (int j = 0; j <= n-len; ++j) {
                    for (int x = 1; x < len && !dp[i][j][len]; ++x) {
                        dp[i][j][len] = dp[i][j][x] && dp[i+x][j+x][len-x]
                        || dp[i][j+len-x][x] && dp[i+x][j][len-x];
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};
