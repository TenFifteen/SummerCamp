/*
题目大意：
有一堆石子，两个人轮流拿。每次可以拿1-3个。
最后一个拿完石子的人获胜。
问第一个人是否有必胜策略

解题思路：
如果是1-3个可以必胜，但是4个不可以必胜。
然后可以总结出来，如果是4的倍数，则不可以必胜。

遇到的问题：
的确是个简单题。

再次阅读：
还是简单题。
*/
class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};
/*
第二次做：
非常简单。
*/
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};