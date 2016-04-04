/*
题目大意：
给定a，b，n，求a的n次方再%b

解题思路：
二分。

遇到的问题：
要注意所有有可能溢出的地方。
*/
class Solution {
    long long sub(int a, int b, int n) {
        if (n == 0) return 1 % b;
        
        long long ret = sub(a, b, n/2);
        long long ans = ret*ret%b;
        if (n & 0x1) ans = ans*a%b;
        return ans;
    }
    
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (n == 0) return 1 % b;
        if (n < 0) {
            return 1/fastPower(a, b, -n)%b;
        }
        return sub(a, b, n);
    }
};