/*
题目大意：
计算double的n次方。

解题思路：
二分

遇到的问题：
一开始竟然写成了ans += cur;
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