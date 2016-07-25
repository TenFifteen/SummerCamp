/*
题目大意：
通配符匹配

解题思路：
动态规划。注意题目中的**是可以连着使用的。

遇到的问题：
**竟然可以连着使用。。。

再次阅读：
虽然看到这种题目第一想法就是动归，而且这次也是这种想法，看了之前的代码，感觉已经挺好的了。
然后抱着试一试的心态看了一下DISCUSS，结果人家根本就用的不是动归好不。
虽然DISCUSS中的复杂度说明有点问题，但是这种思路至少省掉了内存开销，而且在很多时候时间复杂度也要
低于m*m复杂度。所以肯定是优于我的那种动归的方案的。
代码其实还算好懂吧。就是让*先匹配0个字符，然后是1个然后是2个等等。
bool isMatch(const char *s, const char *p) {
    const char* star=NULL;
    const char* ss=s;
    while (*s){
        //advancing both pointers when (both characters match) or ('?' found in pattern)
        //note that *p will not advance beyond its length
        if ((*p=='?')||(*p==*s)){s++;p++;continue;}

        // * found in pattern, track index of *, only advancing pattern pointer
        if (*p=='*'){star=p++; ss=s;continue;}

        //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
        //only advancing pattern pointer
        if (star){ p = star+1; s=++ss;continue;}

       //current pattern pointer is not star, last patter pointer was not *
       //characters do not match
        return false;
    }

   //check for remaining characters in pattern
    while (*p=='*'){p++;}

    return !*p;
}
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> tmp(p.size()+1, false);
        vector<vector<bool>> dp(s.size()+1, tmp);
        dp[0][0] = true;
        for(int i = 0; i < p.size(); ++i){
            if(p[i] != '*')break;
            dp[0][i+1] = true;
        }
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 1; j <= p.size(); ++j){
                if(p[j-1] == '*'){
                    if(dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1]){
                        dp[i][j] = true;
                    }
                }else if(p[j-1] == '?' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
/*
第二次做：
又是用的动归，而且，跟之前基本是一模一样的。。。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == "") {
            for (auto ch : p) {
                if (ch != '*') return false;
            }
            return true;
        }
        if (p == "") return false;

        vector<vector<bool> > dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] != '*') break;
            dp[0][i+1] = true;
        }

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                if (p[j] == '*') {
                    dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j] || dp[i][j];
                } else if (p[j] == '?' || p[j] == s[i]) {
                    dp[i+1][j+1] = dp[i][j];
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};
/*
 *终于写出来star这种方式了。不过写的还不是足够简洁，而且也不是一次性对的，改了好几次
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p == "") return s == "";

        int star = -1, last;
        int i = 0, j = 0;
        while (i < s.size() && j < p.size()) {
            if (p[j] == '?' || p[j] == s[i]) {
                i++;
                j++;
            } else if (p[j] == '*') {
                star = j++;
                last = i+1;
            } else if (star < 0) {
                return false;
            } else {
                i = last++;
                j = star + 1;
            }

            if (j == p.size() && i != s.size() && star >= 0) {
                i = last++;
                j = star + 1;
                if (j == p.size()) return true;
            }
        }

        if (i == s.size() && j == p.size()) return true;
        if (i == s.size()) {
            while (j < p.size() && p[j] == '*') j++;
            return j == p.size();
        } else {
            return false;
        }
    }
};

