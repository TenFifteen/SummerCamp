/*
题目大意：
给定一个排序的数组，和一个target。找到target的位置，或者没有target，但是target
该插入的位置。

解题思路：
二分啊。

遇到的问题：
没有。
*/
class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0) return 0;
        
        int left = 0, right = A.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (A[mid] < target) left = mid+1;
            else right = mid;
        }
        
        if (A[left] >= target) return left;
        else return left+1;
    }
};