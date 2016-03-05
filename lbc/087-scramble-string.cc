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

再次阅读：
感觉这道题的动归解法已经挺不错了。
但是看到DISCUSS中投票数量最多的竟然是用的递归的方式解的：
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;

        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }

        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};
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
/*
第二次做：
这个题目之前已经考虑了很多了，所以方法都记住了。
但是代码写的时候竟然把下标搞错了，让我找了这么好久的错误。
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        
        string t1(s1), t2(s2);
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;
        
        for (int i = 0; i+1 < s1.size(); ++i) {
            if (isScramble(s1.substr(0, i+1), s2.substr(0, i+1))
             && isScramble(s1.substr(i+1), s2.substr(i+1))) return true;
            if (isScramble(s1.substr(0, i+1), s2.substr(s1.size()-i-1))
             && isScramble(s1.substr(i+1), s2.substr(0, s1.size()-i-1))) return true;
        }
        
        return false;
    }
};