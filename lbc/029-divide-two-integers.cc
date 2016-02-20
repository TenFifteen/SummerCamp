/*
题目大意：
在不使用乘法、除法、取模运算的情况下，实现整数的除法。

解题思路：
可以用移位的方法来达到*2的效果，然后每次将除数向左移位，知道大于被除数，然后将此时的倍数记下，
并将被除数减去相应的数量。
鉴于中间结果会有溢出，所以要用long long作为中间结果。

遇到的问题：
这里注意到一定要处理溢出的情况，一开始我还老觉得INT_MIN/-1为啥结果是INT_MAX呢，后来突然想起来，原来
这也算是溢出啊。
所以也就是说一共有两种溢出，一种是除零溢出；一种是INT_MIN/-1溢出。

再次阅读：
看完了题目，第一想法竟然是二分。竟然没有意识到不可以使用乘法。
然后看完了解法之后才意识到是不可以使用乘除取余等操作符。
所以这种解法应该是最优的了。然后看了DISCUSS中的解法，也是这样样子的，
我当时肯定是参考了别人的思路做出来的。
不过这个思路一定要记清楚了，我觉得还是挺重要的。
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)return INT_MAX;
        if(dividend == INT_MIN && divisor == -1)return INT_MAX;
        long long left = dividend;
        long long right = divisor;
        bool neg = false;
        if(left < 0){
            left = -left;
            neg = !neg;
        }
        if(right < 0){
            right = -right;
            neg = !neg;
        }
        int ans = 0;
        while(left >= right){
            long long cur = right;
            int shift = 0;
            while(left >= cur){
                shift++;
                cur = right << shift;
            }
            ans += 1 << (shift - 1);
            left -= right << (shift - 1);
        }
        
        if(neg){
            return -ans;
        }else{
            return ans;
        }
    }
};
/*
第二次做：
这道题竟然忘了改怎么解了，实在是不应该啊。不过知道了之后，竟然代码写的跟之前基本是一样一样的。。。
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (divisor == -1 && dividend == INT_MIN)) return INT_MAX;
        
        long long left = dividend, right = divisor;
        bool neg = false;
        if (left < 0) {
            neg = !neg;
            left = -left;
        }
        if (right < 0) {
            neg = !neg;
            right = -right;
        }
        
        int ans = 0;
        while (left >= right) {
            int mul = 0;
            while (left >= (right << mul)) mul++;
            mul--;
            ans += (1 << mul);
            left -= (right << mul);
        }
        
        if (neg) {
            return -ans;
        } else {
            return ans;
        }
    }
};