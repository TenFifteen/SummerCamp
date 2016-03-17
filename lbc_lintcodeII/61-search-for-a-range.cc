/*
题目大意：
给定一个排序的数组，搜索一个target的区间。

解题思路：
二分。

遇到的问题：
没有。
*/
class Solution {
    int lower(vector<int> &A, int target) {
        int left = 0, right = A.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (A[mid] < target) left = mid+1;
            else right = mid;
        }
        
        if (A[left] == target) return left;
        return -1;
    }
    
    int upper(vector<int> &A, int target) {
        int left = 0, right = A.size()-1;
        while (left < right) {
            int mid = left + (right-left+1)/2;
            if (A[mid] > target) right = mid-1;
            else left = mid;
        }
        
        if (A[left] == target) return left;
        return -1;
    }
    
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> ans(2, -1);
        if (A.size() == 0) return ans;
        
        ans[0] = lower(A, target);
        ans[1] = upper(A, target);
        return ans;
    }
};