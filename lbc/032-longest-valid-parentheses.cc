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

再次阅读：
一开始看到题目，首先是一个暴力的搜索。
然后低头一看，原来用的竟然是个动归，然后就立马想起来动归的解法了。
不过看了一下之前的代码，应该是有问题的，估计是样例不够吧，比如()()这种模式，应该就是错误的。
不过也挺容易修复的。
计算一下复杂度的话，大约是有可能n*n的。

然后看了一下DISCUSS，竟然最好的解法都是用的栈来解决的。而且，都是线性复杂度。
基本思路就是将一个stack来存放当前遍历过的没有匹配到的括号，然后遍历完了，之后，就知道了所有的无法
匹配的括号的位置了。然后通过计算每个不匹配的括号之间的匹配的长度，就可以知道最后最大的匹配长度是多少了。
感觉这个思路还是非常好的，代码如下：
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        if (st.empty()) longest = n;
        else {
            int a = n, b = 0;
            while (!st.empty()) {
                b = st.top(); st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};
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