/*
题目：二分查找 容易

题目大意：
给定一个排序的数组，有重复，问target是否存在于数组中

解题思路：
二分搜索

遇到的问题：
一开始竟然拿mid直接跟target比较了，真是太不应该了。
另外就是注意边界条件的判定。尤其是这种有重复的情况。
*/
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if (array.size() == 0) return -1;
        long long left = 0, right = array.size()-1;
        while (left < right) {
            if (left + 1 == right && array[left] == target) return left; 
            long long mid = left + (right-left)/2;
            if (array[mid] < target) {
                left = mid+1;
            } else if (array[mid] > target) {
                right = mid-1;
            } else {
                right = mid;
            }
        }
        if (array[left] == target) return left;
        return -1;
    }
};
