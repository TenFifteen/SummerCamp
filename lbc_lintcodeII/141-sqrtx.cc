/*
题目大意：
求平方根。

解题思路：
二分。

遇到的问题：
一开始处理的有溢出风险。
*/
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        //assert(x >= 0);
        
        if (x < 2) return x;
        
        int left = 0, right = x-1;
        while (left < right) {
            int mid = left + (right-left+1)/2;
            if (x/mid == mid) return mid;
            else if (x/mid > mid) left = mid;
            else right = mid-1;
        }
        
        return left;
    }
};