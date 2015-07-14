/*
题目大意：
一个排序的数组，从某个位置偏移了，类似于4560123这样子。给定一个target，找出其index，
或者没有就返回-1.

解题思路：
就是二分搜索，不过在确定下一次的搜索边界的时候，一定要注意这是一个rotate的排序数组就好了。

遇到的问题：
本来觉得这个问题好难的。可以竟然一次通过了。
不过题目中的各种条件还是要注意一下的。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (right-left)/2 + left;
            if(nums[mid] == target)return mid;
            if(nums[mid] < target){
                if(nums[right] > nums[mid]){
                    if(nums[right] >= target){
                        left = mid+1;
                    }else{
                        right = mid-1;
                    }
                }else{
                    left = mid+1;
                }
            }else{
                if(nums[right] > nums[mid]){
                    right = mid-1;
                }else{
                    if(nums[left] <= target){
                        right = mid-1;
                    }else{
                        left = mid+1;
                    }
                }
            }
        }
        return -1;
    }
};