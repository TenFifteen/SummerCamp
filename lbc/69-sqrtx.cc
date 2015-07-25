/*
题目大意：
给一个x，求平方根。

解题思路：
二分法，逐渐逼近。

遇到的问题：
一开始考虑乘法会溢出，mid用了long long。结果竟然边界都会溢出，最后将left和right也都改为了long long，
也就是说无时无刻不应该考虑边界啊。
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0;
        if(x <= 2)return 1;
        long long left = 1, right = x;
        while(left <= right){
            if(left == right){
                if(left*left <= x)return left;
                return left-1;
            }else if(left+1 == right){
                if(right*right <= x)return right;
                if(left*left <= x)return left;
                return left-1;
            }
            long long mid = left + (right-left)/2;
            if(mid*mid == x)return mid;
            if(mid*mid < x){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }
};