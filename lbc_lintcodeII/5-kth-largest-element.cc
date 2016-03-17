/*
题目大意：
求第k大的数。

解题思路：
快排思想

遇到的问题：
没有太大问题。
*/
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int left = 0, right = nums.size()-1;
        
        while (left < right) {
            int L = left, R = right;
            int mid = nums[L];
            while (L < R) {
                while (L < R && nums[R] < mid) R--;
                nums[L] = nums[R];
                while (L < R && nums[L] >= mid) L++;
                nums[R] = nums[L];
            }
            nums[L] = mid;
            
            if (L == k-1) return nums[L];
            else if (L < k-1) left = L+1;
            else right = L-1;
        }
        
        return nums[left];
    }
};