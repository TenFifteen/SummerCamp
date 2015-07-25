/*
题目大意：
一个字符串可以看做一个二叉树。
判断两个字符串是否是经过了二叉树的旋转得到的。

解题思路：
动态规划。对于一个字符串，如果长度是1，那么就是恰好相等时为true；
要不然就将字符串划分为两个字串，a1，a2和b1，b2
如果a1 == b1 && a2 == b2
或者a2 == b1 && a2 == b1
那么就是true
要不然就是false

遇到的问题：
中间的转化的一个下标搞错了，检查了好久。这种边界问题一定要好好的注意。
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())return false;
        if(s1 == s2)return true;
        vector<bool> tmp1(s1.size(), false);
        vector<vector<bool>> tmp2(s1.size(), tmp1);
        vector<vector<vector<bool>>> dp(s1.size(), tmp2);
        for(int i = 0; i < s1.size(); ++i){
            for(int j = 0; j < s2.size(); ++j){
                dp[0][i][j] = (s1[i] == s2[j]);
            }
        }
        for(int k = 1; k < s1.size(); ++k){
            for(int i = 0; i < s1.size()-k; ++i){
                for(int j = 0; j < s1.size()-k; ++j){
                    for(int x = 0; x < k; ++x){
                        if((dp[x][i][j] && dp[k-x-1][i+x+1][j+x+1]) || (dp[x][i][j+k-x] && dp[k-x-1][i+x+1][j])){
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[s1.size()-1][0][0];
    }
};