/*
题目大意：
给定一个排序的数组，保证其中的数字都是唯一的。然后给定一个target，插入到数组中。
求插入的位置。

解题思路：
用二分法，当只有一个或者两个元素的时候，直接给出结果。

遇到的问题：
竟然又直接做对了，不过还是要注意边界，尤其是> 和>= 这两种不同的情况。
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)return 0;
        int left = 0, right = nums.size()-1;
        while(left <= right){
            if(left == right){
                if(nums[left] >= target){
                    return left;
                }else{
                    return left+1;
                }
            }
            if(left+1 == right){
                if(nums[left] >= target)return left;
                if(nums[right] >= target)return right;
                return right+1;
            }
            
            int mid = left + (right-left)/2;
            if(nums[mid] == target)return mid;
            if(nums[mid] > target){
                right = mid;
            }else{
                left = mid;
            }
        }
    }
};