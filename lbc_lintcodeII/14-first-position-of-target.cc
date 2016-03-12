/*
题目大意：
给定一个排序的数组，问第一个target的下标，如果没有就是-1

解题思路：
二分

遇到的问题：
二分还是很容易出问题。。。
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
        
        long long left = 0, right = array.size();
        right--;
        
        while (left < right) {
            long long mid = (left+right)/2;
            if (array[mid] >= target) right = mid;
            else left = mid+1;
        }
        
        return array[left] == target ? left : -1;
    }
};