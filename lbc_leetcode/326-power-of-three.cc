/*
题目大意：
给定一个int，问是否是3的幂次的数字。

解题思路：
正常的解法应该使用循环，将所有的素数因子3除掉，然后就可以判断了。
然后更好一点的可以直接将所有3的幂次的数字都算出来，然后用hash。
可是我无论如何也想不到这种找到上限，然后一次性取模的方式啊。

遇到的问题：
一开始没有想到这么好的解法，最多想到了hash。

再次阅读：
已经看过了DISCUSS中最好的解法了，所以没有必要再看了。
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        return 1162261467 % n == 0;
    }
};
/*
第二次做：
这次知道了有这么一个简便的方法了。
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        return 1162261467 % n == 0;
    }
};
/*
 * most trick question.
 * but answer is so beautiful.
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        return 1162261467 % n == 0;
    }
};
