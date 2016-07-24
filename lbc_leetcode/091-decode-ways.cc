/*
题目大意：
给定一个映射，二十六个字母分别映射1-26，然后给定一个数字串，计算有多少种组合的可能。

解题思路：
动态规划。

遇到的问题：
一开始并没有考虑会有不合法的情况。

再次阅读：
一看就知道是动归。
但是这道题目，需要随时考虑不合法的情形。
而且呢，动归的空间复杂度是可以压缩掉的。
DISCUSS中有一个压缩掉空间复杂度的动归版本：
int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1]
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s == "")return 0;
        if(s[0] == '0')return 0;
        vector<int> ans(s.size()+1, 0);
        ans[0] = 1;
        ans[1] = s[0] == '0' ? 0 : 1;
        for(int i = 1; i < s.size(); ++i){
            int tmp = s[i]-'0';
            tmp += (s[i-1]-'0')*10;
            if(s[i] == '0'){
                if(s[i-1] == '0' || s[i-1] > '2')return 0;
                ans[i+1] = ans[i-1];
            }else{
                if(tmp > 9 && tmp < 27){
                    ans[i+1] = ans[i-1] + ans[i];
                }else{
                    ans[i+1] = ans[i];
                }
            }
        }
        return ans[s.size()];
    }
};
/*
第二次做：
思路是有的，代码写起来比较费劲，而且也不是很好看。需要加强。
*/
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) {
            if (s == "0") return 0;
            return 1;
        }

        int n = s.size();
        vector<int> dp(n, 0);
        dp[n-1] = s[n-1] == '0' ? 0 : 1;
        if (s[n-2] != '0') {
            dp[n-2] = dp[n-1];
            if (s[n-2] == '1' || s[n-2] == '2' && s[n-1] < '7') dp[n-2] += 1;
        }

        for (int i = n-3; i >= 0; --i) {
            if (s[i] != '0') {
                dp[i] = dp[i+1];
                if (s[i] == '1' || s[i] == '2' && s[i+1] < '7') dp[i] += dp[i+2];
            }
        }

        return dp[0];
    }
};
/*
 * simplify code
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;

        vector<int> dp(s.size()+1, 1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') dp[i+1] = 0;
            else dp[i+1] = dp[i];
            if (i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))) dp[i+1] += dp[i-1];
        }
        return dp[s.size()];
    }
};
