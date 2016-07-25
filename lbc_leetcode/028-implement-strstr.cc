/*
题目大意：
给一个字符串，一个模式串，找出模式串在字符串中第一次出现的位置；没有则返回-1；

解题思路：
应该是用KMP解这种题目的。可是为啥最简单的方法就过了。

遇到的问题：
一定要记得容器size返回的是unsigned。

再次阅读：
其实这就是一个裸的KMP，但是既然是一个简单题目，其实可以直接用暴力的方法的了。
感觉之前的写法已经差不多够用了。
然后在DISCUSS中看到一种更简洁的，虽然不是很直观，但是毕竟代码比较简洁，可以一看：
int strStr(char *haystack, char *needle) {
        if (!haystack || !needle) return -1;
        for (int i = 0; ; ++i) {
            for (int j = 0; ; ++j) {
                if (needle[j] == 0) return i;
                if (haystack[i + j] == 0) return -1;
                if (haystack[i + j] != needle[j]) break;
            }
        }
    }
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size())return -1;
        for(int i = 0; i < haystack.size()-needle.size()+1; ++i){
            bool found = true;
            for(int j = i; j < i+needle.size(); ++j){
                if(haystack[j] != needle[j-i]){
                    found = false;
                    break;
                }
            }
            if(found)return i;
        }
        return -1;
    }
};
/*
第二次做：
感觉跟之前的代码竟然完全一样的感觉。。。
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;

        if (haystack == "" && needle == "") return 0;//don't know why

        for (int i = 0; i < haystack.size()+1-needle.size(); ++i) {
            bool found = true;
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i+j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }

        return -1;
    }
};
/*
 * 还是用的老办法，不过KMP最好还是再看看
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        for (int i = 0; i <= haystack.size()-needle.size(); ++i) {
            bool found = true;
            for (int j = 0; j < needle.size(); ++j) {
                if (needle[j] != haystack[i+j]) {
                    found = false;
                    break;
                }
            }
            if (found) return i;
        }
        return -1;
    }
};
