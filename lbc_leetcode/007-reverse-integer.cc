/*
题目大意：
给定一个整数int，然后翻转其数字位，符号位不变。

解题思路：
由于需要考虑溢出的问题，包括负数转正数溢出，翻转后溢出两种情况。所以采用了long long的中间结果；
最后强转为int，如果没有变化，则说明没有溢出。溢出时输出0

遇到的问题：
一开始没考虑溢出的问题。感觉这种整数操作都需要考虑溢出的问题，所以简单题更要细心。

再次阅读：
这道题本身主要是考察整数的属于范围以及溢出等情况的。
原来的做法并没有太大问题，不过我在DISCUSS上看到了一个更简便的方法，如下（java）：
public int reverse(int x)
{
    int result = 0;

    while (x != 0)
    {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if ((newResult - tail) / 10 != result)
        { return 0; }
        result = newResult;
        x = x / 10;
    }

    return result;
}

*/
class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        long long xx = x;
        if(xx < 0){
            neg = true;
            xx = -xx;
        }
        long long ans = 0;
        while(xx){
            ans *= 10;
            ans += xx%10;
            xx /= 10;
        }
        int out = ans;
        if(out != ans){
            return 0;
        }
        if(neg){
            return -out;
        }else{
            return out;
        }
    }
};
/*
第二次做：
虽然做出来了，但是总感觉不是很简洁。
看到之前DISCUSS中的那种写法，竟然可以不考虑负数！！！！！！！
*/
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        
        bool neg = false;
        if (x & 0x80000000) {
            neg = true;
            x = -x;
        }
        
        int ans = 0;
        while (x) {
            int new_ans = ans * 10;
            new_ans += x % 10;
            x /= 10;
            
            if (new_ans/10 != ans) return 0;
            ans = new_ans;
        }
        if (neg) return -ans;
        else return ans;
    }
};