/*
题目：字符串查找 容易

题目大意：
给定一个源字符串，一个目标字符串，问目标字符串是否可以在源字符串中找到。
找到返回下标，找不到就返回-1

解题思路：
题目要求，暴力匹配可解。
但是KMP更优，所以就练习了一下KMP

遇到的问题：
KMP实在是不太好记，next数组的更新，我到现在还只是模模糊糊的理解一点。

KMP的详细参考资料：
http://blog.csdn.net/v_july_v/article/details/7041827
http://kenby.iteye.com/blog/1025599
*/
class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (source == NULL || target == NULL) return -1;
        int len_s = strlen(source);
        int len_t = strlen(target);
        if (len_s < len_t) return -1;
        int next[len_t+1];
        next[0] = next[1] = 0;
        int k = 0;
        for (int i = 2; i <= len_t; ++i) {
            while (k != 0 && target[k] != target[i-1]) k = next[k];
            if (target[k] == target[i-1]) k++;
            next[i] = k;
        }
        int i = 0, j = 0;
        while (i < len_s && j < len_t) {
            if (source[i] == target[j]) {
                i++;
                j++;
            } else if (j == 0) {
                i++;
            } else {
                j = next[j];
            }
        }
        if (j == len_t) return i-j;
        return -1;
    }
};

