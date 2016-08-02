/*
题目大意：
给定一个字符串，问在通过在字符串前面加字符的方式将其变为回文字符串，最短的结果是多少？

解题思路：
计算以字符串开头为起点的最长的回文子串。

遇到的问题：
虽然一开始想到了这个解法，但是感觉Manchester并不能直接写出来，就试了一个朴素的解法，不出意料，超时了。
得到的的结果就是Manchester算法一定要熟练掌握。

再次阅读：
本来以为这道题最好就是用这种Manchester算法解呢，结果看到DISCUSS中用的最多的竟然是KMP算法。
正好可以表达这件事。当然了，KMP算法的next数组，也就是以字符串开头的最长的回文子串。
然后就在这里贴一个如何求KMP算法的next数组的代码吧，感觉这东西好像很容易就忘了：
void makeNext(const char P[],int next[])
{
    int q,k;//q:模版字符串下标；k:最大前后缀长度
    int m = strlen(P);//模版字符串长度
    next[0] = 0;//模版字符串的第一个字符的最大前后缀长度为0
    for (q = 1,k = 0; q < m; ++q)//for循环，从第二个字符开始，依次计算每一个字符对应的next值
    {
        while(k > 0 && P[q] != P[k])//递归的求出P[0]···P[q]的最大的相同的前后缀长度k
            k = next[k-1];          //不理解没关系看下面的分析，这个while循环是整段代码的精髓所在，确实不好理解
        if (P[q] == P[k])//如果相等，那么最大相同前后缀长度加1
        {
            k++;
        }
        next[q] = k;
    }
}
下面这段代码就是用的KMP的思想，还是非常值得学习的：
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() < 2)return s;
        string str(s.size()*2+1,'#');
        for(int i = 0; i < s.size(); ++i){
            str[i*2+1] = s[i];
        }
        int id = 0, mx = 0, cur = 0;
        vector<int> len(str.size(), 1);
        while(cur < str.size()){
            if(cur < mx){
                len[cur] = min(mx-cur, len[2*id-cur]);
            }
            while(cur - len[cur] >= 0 && cur+len[cur] < str.size() && str[cur-len[cur]] == str[cur+len[cur]]){
                len[cur]++;
            }
            if(cur + len[cur] > mx){
                mx = cur + len[cur];
                id = cur;
            }
            cur++;
        }
        int max_p = str.size()/2+1;
        while(len[max_p] != max_p+1)max_p--;
        string pad = s.substr(max_p, s.size());
        for(int i = 0; i < pad.size()/2; ++i){
            swap(pad[i], pad[pad.size()-1-i]);
        }
        return pad + s;
    }
};
/*
第二次做：
问题不是很大。
有两个小疏漏，一个是忘记了初始化man字符串了，另一个是index搞错了。
这道题目的最长回文字串的解法基本就是这样了，回头考虑一下用KMP的模式数组解一下。
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() < 2) return s;

        string man(s.size()*2+1, '#');
        for (int i = 0; i < s.size(); ++i) {
            man[i*2+1] = s[i];
        }
        vector<int> dp(man.size(), 1);

        int id = 0, mx = 0;
        for (int i = 0; i < dp.size(); ++i) {
            if (mx > i) dp[i] = min(mx-i+1, dp[id*2-i]);
            while (i-dp[i] >= 0 && dp[i]+i < dp.size() && man[i-dp[i]] == man[i+dp[i]]) dp[i]++;
            if (dp[i]+i-1 > mx) {
                mx = dp[i]+i-1;
                id = i;
            }
        }

        int index = 0;
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i] == i+1) index = i;
        }

        string prefix = s.substr(index);
        for (int i = 0; i < prefix.size()/2; ++i) {
            swap(prefix[i], prefix[prefix.size()-1-i]);
        }
        return prefix + s;
    }
};
/*
 * KMP is still out of my control.
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() < 2) return s;
        string str(s.size()*2+1, '#');
        for (int i = 0; i < s.size(); ++i) str[i*2+1] = s[i];
        vector<int> dp(str.size(), 1);
        int id = 0, mx = 0, ans = 1;
        for (int i = 1; i < str.size(); ++i) {
            if (mx > i) dp[i] = min(dp[id*2-i], mx-i+1);
            while (i-dp[i] >= 0 && i+dp[i] < str.size() && str[i-dp[i]] == str[i+dp[i]]) dp[i]++;
            if (i+dp[i]-1 > mx) {
                mx = i+dp[i]-1;
                id = i;
            }
            if (dp[i] > i) ans = i;
        }
        return string(s.rbegin(), s.rbegin()+s.size()-ans) + s;
    }
};
