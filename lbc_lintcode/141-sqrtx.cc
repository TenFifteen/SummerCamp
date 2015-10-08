/*
题目：23 % x的平方根 容易

题目大意：
快速求平方根

解题思路：
二分

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        long long left = 0, right = x;
        int ret = -1;
        while (left <= right) {
            long long mid = left + (right-left+1)/2;
            if (mid * mid == x) return mid;
            if (mid * mid < x) {
                if (ret == -1) {
                    ret = mid;
                } else {
                    if (ret < mid) {
                        ret = mid;
                    }
                }
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return ret;
    }
};
