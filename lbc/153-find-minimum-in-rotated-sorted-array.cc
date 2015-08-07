/*
题目大意：
给定一个数组，本来是排序的。现在是旋转了一段。相当是：45670123

解题思路：
二分查找。

遇到的问题：
还是各种边界问题，莫非今天不适合刷题？
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(nums[right] > nums[left]){
                return nums[left];
            }else{
                if(nums[mid] > nums[left]){
                    left = mid+1;
                }else if(nums[mid] > nums[mid-1]){
                    right = mid-1;
                }else{
                    return nums[mid];
                }
            }
        }
        return nums[left];
    }
};