/*
题目大意：
给定一个字符串，问在所有切分后子串都是回文串的方案中，哪个方案的切分方式最少。

解题思路：
动态规划。对于回文串的判断也用个动态规划，可以将复杂度从n*n*n降到n*n

遇到的问题：
一开始按照131的方式做，结果超时。
看了别人的方法，才知道用动态规划并且压缩判断回文的过程才能达到时间要求。
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