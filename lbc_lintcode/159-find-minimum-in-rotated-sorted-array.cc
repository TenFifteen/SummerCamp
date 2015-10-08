/*
题目：33 % 寻找旋转排序数组中的最小值 中等

题目大意：
给定一个排序的数组，然后数组旋转一下，求最小值

解题思路：
二分。

遇到的问题：
二分就要注意收敛
*/
class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int left = 0, right = num.size()-1;
        while (left <= right) {
            if (left == right) return num[left];
            if (left + 1 == right) return min(num[left], num[right]);
            int mid = left + (right-left+1)/2;
            if (num[left] > num[right]) {
                if (num[mid] > num[left]) {
                    left = mid+1;
                } else {
                    right = mid;
                }
            } else {
                return num[left];
            }
        }
        return num[left];
    }
};
