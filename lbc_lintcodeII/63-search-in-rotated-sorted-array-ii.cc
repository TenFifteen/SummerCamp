/*
题目大意：
给定一个有序的旋转数组，并且有重复元素。问target是否在数组中。

解题思路：
见代码。

遇到的问题：
这个题目还是做得不是很熟练，所以还是看看之前的代码吧。
*/
class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0) return false;
        
        int left = 0, right = A.size()-1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (A[mid] == target) return true;
            
            if (A[left] == A[right]) right--;
            else if (A[left] < A[right]) {
                if (A[mid] < target) left = mid+1;
                else right = mid-1;
            } else {
                if ((A[mid] >= A[left] && A[mid] < target) || (A[mid] < A[left] && A[mid] < target && A[right] >= target) || (A[mid] >= A[left] && A[left] > target)) left = mid+1;
                else right = mid-1;
            }
        }
        
        return false;
    }
};