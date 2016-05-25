/*
题目大意：
给定一个字符串，问在所有切分后子串都是回文串的方案中，哪个方案的切分方式最少。

解题思路：
动态规划。对于回文串的判断也用个动态规划，可以将复杂度从n*n*n降到n*n

遇到的问题：
一开始按照131的方式做，结果超时。
看了别人的方法，才知道用动态规划并且压缩判断回文的过程才能达到时间要求。

再次阅读：
首先，判断回文的过程应该单独写一个方法，要不然体现不出编程水平。
然后，我这次想到的方法是一个n的三次方的方法，不用递归。而是直接用动归dp[i][j]
表示[i,j]区间这段字符串，最少的拆分数量是多少？

然后，看了一下之前代码中的DP，感觉其实是一样的，只不过他们的dp[i]表示，从i到最后
这段字符串的最少的拆分数量是多少？
另外，就是其中的buf数组是个关键。
DISCUSS中第二好的方案就是这个。看来当时参考的那个人也是参考的DISCUSS中的东西啊。

然后，DISCUSS中还有一个更厉害的想法：
感觉这个想法实在是好极了，但是非常的不直观的可以想出来。简直厉害🐂
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};

*/
class Solution {
public:
    int minCut(string s){
        if(s.size() < 2)return 0;
        vector<int> dp(s.size(), INT_MAX);
        vector<vector<bool>> buf(s.size(), vector<bool>(s.size(), false));
        dp[s.size()-1] = 0;
        for(int i = s.size()-2; i >= 0; --i){
            if(s[i] == s[s.size()-1]){
                if(s.size()-i <= 2 || buf[i+1][s.size()-2]){
                    dp[i] = 0;
                    buf[i][s.size()-1] = true;
                }
            }
            for(int j = i+1; j < s.size(); ++j){
                if(s[i] == s[j-1] && (j-i<3 || buf[i+1][j-2] == true)){
                    buf[i][j-1] = true;
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[0];
    }

    int minCut2(string s) {
        if(s.size() < 2)return 0;
        bool isPa = true;
        for(int i = 0; i < s.size()/2; ++i){
            if(s[i] != s[s.size()-1-i]){
                isPa = false;
                break;
            }
        }
        if(isPa)return 0;
        
        int ret = INT_MAX;
        for(int i = s.size()-2; i >= 0; --i){
            isPa = true;
            for(int j = 0; j < (i+1)/2; ++j){
                if(s[j] != s[i-j]){
                    isPa = false;
                    break;
                }
            }
            if(isPa){
                int tmp = minCut(s.substr(i+1, s.size()-1-i));
                if(tmp < ret){
                    ret = tmp;
                }
            }
        }
        return ret+1;
    }
};
/*
第二次做：
这次还是没有想出来怎么做到n*n的复杂度。还是参考的原来的思路。
感觉真是烦人啊，怎么老是忘记呢。或者说根本想不出来呢。
*/
class Solution {
public:
    int minCut(string s) {
        if (s.size() < 2) return 0;
        
        int n = s.size();
        vector<int> dp(n, 0);
        vector<vector<bool>> buf(n, vector<bool>(n, true));
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < n-len+1; ++i) {
                if (len == 2) {
                    buf[i][i+len-1] = s[i] == s[i+1];
                } else {
                    buf[i][i+len-1] = s[i] == s[i+len-1] && buf[i+1][i+len-2];
                }
            }
        }
        
        for (int i = 1; i < n; ++i) {
            if (buf[0][i] == false) {
                dp[i] = INT_MAX;
                for (int j = i; j > 0; --j) {
                    if (buf[j][i]) {
                        dp[i] = min(dp[i], dp[j-1]+1);
                    }
                }
            }
        }
        
        return dp[n-1];
    }
};