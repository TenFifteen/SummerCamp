/*
题目大意：
判断第一个bad的version 

解题思路：
二分。

遇到的问题：
没有。
*/
/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
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
            int mid = left + (right-left)/2;
            if (SVNRepo::isBadVersion(mid)) right = mid;
            else left = mid+1;
        }
        return left;
    }
};
