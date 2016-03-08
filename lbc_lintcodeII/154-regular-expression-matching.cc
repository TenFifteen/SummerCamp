/*
题目大意：
正则表达式匹配。.表示一个任意字符; *表示其前面的字符可以有0到n个。

解题思路：
动归。

遇到的问题：
一开始把条件中的p[j-1] == '*' 写成了s[j-1] == '*'，找了半天。
另外就是本来觉得不应该判断开头就有*的这种情况，结果真的有这种测试用例。
*/
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        int lenS = strlen(s), lenP = strlen(p);
        
        if (*p == '*') return false;
        
        vector<vector<bool>> dp(lenS+1, vector<bool>(lenP+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= lenP; ++i) {
            if (*(p+i-1) == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }
        
        for (int i = 1; i <= lenS; ++i) {
            for (int j = 1; j <= lenP; ++j) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || dp[i][j-1] 
                    || ((p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j]);
                }
            }
        }
        
        return dp[lenS][lenP];
    }
};