/*
题目大意：
找出一个字符串中最长的回文子串。保证只有一条这样的回文子串。

解题思路：
首先将字符串扩展，在用特殊字符隔开原来的每个字符，包括两头的。这样可以确保在扩展之后的字符串中，
所有的回文子串都是奇数长度的。
用mx来记录之前找过的最远的回文子串的边界，id对应那个回文子串的中心。
然后从前完后处理字符串，如果当前的位置比mx大，则初始化len[cur] 为1，也就是这时候只有这一个字母是回文的；
如果当前的位置比mx小，则由于对称性，cur关于id对称的地方肯定是处理过的。那么也就是初始化为len[2*id-cur]，
但是如果这个初始值加上cur比mx都大的话，就不合理了，所以要跟mx-cur取一个最小。
这个算法成为Manchester算法，据说可以是线性的。
时间复杂度：n；空间复杂度：n

遇到的问题：
这个题目一开始使用了动态规划的方法，是标准的n*n的复杂度。
但是竟然是超时。我都开始怀疑是自己写错了，还是它要求太严格了。
下面的代码中，包括了动态规划的代码，还是值得借鉴的。
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1)return s;
        string str(s.size()*2+1,'#');
        for(int i = 0; i < s.size(); ++i){
            str[i*2+1] = s[i];
        }
        int id = 0;
        int mx = 0;
        int cur = 0;
        vector<int> len(s.size()*2+1,1);
        while(cur < str.size()){
            if(cur < mx){
                len[cur] = min(mx-cur,len[2*id-cur]);
            }
            while(cur-len[cur] >= 0 && cur+len[cur] < str.size() && str[cur-len[cur]] == str[cur+len[cur]]){
                len[cur]++;
            }
            if(cur + len[cur] > mx){
                mx = cur+len[cur];
                id = cur;
            }
            cur++;
        }
        int ans = 0;
        for(int i = 1; i < str.size(); ++i){
            if(len[i] > len[ans]){
                ans = i;
            }
        }
        string ret = str.substr(ans-len[ans]+1, len[ans]*2-1);
        string res;
        for(int i = 1; i < ret.size(); i+=2){
            res.push_back(ret[i]);
        }
        return res;
    }

    string longestPalindrome2(string s) {
        if(s.size() <= 1)return s;
        vector<bool> tmp(s.size(), false);
        vector<vector<bool>> dp(s.size(), tmp);
        for(int i = 0; i < s.size(); ++i){
            dp[i][i] = true;
        }
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
            }
        }
        int ans = 0;
        int len = 1;
        for(int i = 2; i < s.size(); ++i){
            for(int j = 0; j < s.size()-i; ++j){
                if(dp[j+1][i-2] && s[j] == s[j+i]){
                    dp[j][i] = true;
                    ans = j;
                    len = i;
                }
            }
        }
        return s.substr(ans,len+1);
    }

    string longestPalindrome1(string s) {
        if(s.size() <= 1)return s;
        
        string str = "#";
        for(int i = 0; i < s.size(); ++i){
            str.push_back(s[i]);
            str.push_back('#');
        }
        
        vector<bool> tmp(str.size()/2, false);
        vector<vector<bool>> dp(str.size(),tmp);
        for(int i = 0; i < str.size(); ++i){
            dp[i][0] = true;
        }
        int flag = -1;
        int len = 0;
        for(int i = 1; i < str.size()/2+1; ++i){
            bool has = false;
            for(int j = i; j < str.size()-i; ++j){
                if(dp[j][i-1] && str[j-i] == str[j+i]){
                    dp[j][i] = true;
                    flag = j;
                    len = i;
                    has = true;
                }
            }
            if(!has)break;
        }
        if(flag % 2){
            return s.substr(flag/2 - len/2, len+1);
        }else{
            return s.substr(flag/2-len/2,len);
        }
    }
};