/*
题目：34 % 第一个错误的代码版本 中等

题目大意：
有一个数组，其中从某一个数字开始，后面的都是坏的，找到第一个坏的

解题思路：
二分

遇到的问题：
没有问题。
*/
/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right-left+1)/2;
            if (VersionControl::isBadVersion(mid)) right = mid-1;
            else left = mid+1;
        }
        if (VersionControl::isBadVersion(left))return left;
        return left+1;
    }
};

