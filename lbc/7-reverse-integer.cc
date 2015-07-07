/*
题目大意：
给定一个整数int，然后翻转其数字位，符号位不变。

解题思路：
由于需要考虑溢出的问题，包括负数转正数溢出，翻转后溢出两种情况。所以采用了long long的中间结果；
最后强转为int，如果没有变化，则说明没有溢出。溢出时输出0

遇到的问题：
一开始没考虑溢出的问题。感觉这种整数操作都需要考虑溢出的问题，所以简单题更要细心。
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