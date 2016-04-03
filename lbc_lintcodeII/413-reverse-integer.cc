/*
题目大意：
给定一个int，将其的十进制digit翻转。

解题思路：
见代码。

遇到的问题：
除法和取模的取整问题的确是挺难记住的。
可以参考如下链接：http://www.jianshu.com/p/452c1a5acd31
*/
class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        long long ans = 0;
        while (n) {
            ans *= 10;
            ans += n % 10;
            n /= 10;
        }
        
        if (ans <= INT_MIN || ans >= INT_MAX) return 0;
        return ans;
    }
};