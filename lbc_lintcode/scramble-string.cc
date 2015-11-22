/*
题目：29 % 攀爬字符串 困难

题目大意：
给定两个字符串，问是否是可以通过交换子树的方式互相转换？

解题思路：
一开始用的动归，n的四次方的解法。
后来看到lintcode上要求挑战n的三次方的解法。但是在网上怎么也找不到。
突然在一个早晨，想到了一个好像不错的定律。
就是一个字符串可以通过子树的变换变成任意一个字符串。也就是所有的字母组合的
字符串都可以。然后就是判断两个字符串是否包含同样的字母就可以了。
hash是n的时间和空间。排序是nlogn的时间和0的空间。

遇到的问题：
一开始无法证明自己的想法，先试用这种思路A掉了这道题。
然后用手模拟了三个字母的字符串，的确是可以。
但是我还是没有办法证明n个的也是这样。
*/
class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        // Write your code here
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        return s1 == s2;
    }
};
