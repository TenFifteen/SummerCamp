/*
题目大意：
计算double的n次方。

解题思路：
二分

遇到的问题：
一开始竟然写成了ans += cur;

再次阅读：
一看之前的代码感觉就有点乱，连个空行都没有，都不敢相信自己写的代码。
如果让我重新写的话，我会用到移位和&，但是比这种看起来应该是舒服很多。
看了一下DISCUSS，还有一种递归的写法，写的非常的简洁，也可以借鉴一下。
public class Solution {
    public double pow(double x, int n) {
        if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
}
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0)return 0;
        if(n == 0)return 1;
        bool neg = false;
        if(n < 0){
            neg = true;
            n = -n;
        }
        double ans = 1;
        double cur = x;
        for(int i = 0; i < 32; ++i){
            if(1<<i & n){
                ans *= cur;
            }
            cur = cur*cur;
        }
        if(neg){
            return 1/ans;
        }else{
            return ans;
        }
    }
};
/*
第二次写：
这次还是犯了很多之前犯得小毛病。这道题还真得小心点了。
还有就是DISUCSS中那种递归的思路还是挺不错的。
*/
class Solution {
private:
    double pow(double x, long long n) {
        if (n == 0) return 1.0;
        if (n < 0) return 1/pow(x, -n);
        
        double ans = 1.0;
        double cur = x;
        long long mul = 1;
        while (n) {
            if (n & mul) {
                n -= mul;
                ans *= cur;
            }
            
            cur *= cur;
            mul <<= 1;
        }
        
        return ans;
    }
    
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};