/*
题目大意：
斐波那契数列

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if (n == 1) return 0;
        
        int a = 0, b = 1;
        for (int i = 2; i < n; ++i) {
            int c = a+b;
            a = b;
            b = c;
        }
        
        return b;
    }
};
