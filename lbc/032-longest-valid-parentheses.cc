/*
题目大意：
给一个由左右括号组成的字符串，找出该字符串中最长的匹配的字串的长度。

解题思路：
采用动态规划，定义dp[i]为以i为最后一个字符的字串的最大长度。
当s[i]为(时，结果就是0；
当s[i]为)并且s[i-1]为(时，结果是dp[i-2]+2;
当s[i]为)并且s[i-1]为）时，则需要递推的往前找，知道无法匹配。
时间复杂度应该是n吧，空间复杂度是n

遇到的问题：
一开始这个题目感觉像是动态规划，但是直接想到了二维的动归，而且计算起来应该是n的三次方。
而且找到了一维动归后，还是忘记了))这种情况需要递推往前找的。
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2)return 0;
        vector<int> dp(s.size(), 0);
        int ans = 0;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == '('){
                dp[i] = 0;
            }else{
                if(s[i-1] == '('){
                    if(i == 1){
                        dp[i] = 2;
                    }else{
                        dp[i] = dp[i-2]+2;
                    }
                }else if(dp[i-1] < i && s[i-dp[i-1]-1] == '('){
                    int cur = dp[i-1] + 2;
                    int tmp = i-dp[i-1]-2;
                    while(tmp >= 0 && dp[tmp] != 0){
                        cur += dp[tmp];
                        tmp -= dp[tmp];
                    }
                    dp[i] = cur;
                }else{
                    dp[i] = 0;
                }
            }
            if(dp[i] > ans){
                ans = dp[i];
            }
        }
        return ans;
    }
};