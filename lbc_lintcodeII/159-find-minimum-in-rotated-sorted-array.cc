/*
题目大意：
给定一个有序数组，然后旋转一下，找到其最小值。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if (num.size() == 0) return INT_MIN;
        
        int left = 0, right = num.size()-1;
        while (left < right) {
            if (num[left] < num[right]) return num[left];
            int mid = (left+right) >> 1;
            if (num[mid] < num[right]) right = mid;
            else left = mid+1;
        }
        
        return num[left];
    }
};