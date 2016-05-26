/*
题目大意：
给定一个整数，判断这个整数的各个数字所组成的字符串是否是回文。要求不能使用额外空间。

解题思路：
不适用额外空间，理解为不能将整数转化为字符串。
然后如果是负数的话，直接就是false。
先计算出整数的长度；
然后对于长度的一半（需要考虑一下奇偶），分别判断整数的首尾是否相等，
如果不相等则直接返回false

遇到的问题：
这个题目竟然一次通过，感觉还可以。

再次阅读：
这道题目属于很简单的题目，不过要求不能使用额外的空间。
之前的做法也是可以的的了。
但是现在在DISCUSS中竟然找到一个更好地方法。是通过翻转整数的方式来做的。
但是只是翻转一半就可以了。想法非常的精妙：
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        int len = 0;
        int tmp = x;
        while(tmp){
            len ++;
            tmp /= 10;
        }
        tmp = 1;
        for(int i = 1; i < len; ++i){
            tmp *= 10;
        }
        for(int i = 0; i < len/2; ++i){
            int head = x / tmp;
            int tail = x % 10;
            x %= tmp;
            x /= 10;
            tmp /= 100;
            if(head != tail){
                return false;
            }
        }
        return true;
    }
};
/*
第二次做：
感觉这次跟上次的代码还是有异曲同工之妙啊。
还是DISCUSS中的那种方法巧妙呀！！！！
*/
class Solution {
private:
    int getDigit(int x, int index) {
        if (index != 1) {
            x /= pow(10, index-1);
        }
        return x % 10;
    }
    int getLen(int x) {
        int len = 0;
        while (x) {
            x /= 10;
            len++;
        }
        return len;
    }
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int len = getLen(x);
        for (int i = 0; i < len/2; ++i) {
            if (getDigit(x, i+1) != getDigit(x, len-i)) return false;
        }
        return true;
    }
};