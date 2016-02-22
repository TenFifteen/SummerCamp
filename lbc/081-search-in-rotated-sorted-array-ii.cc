/*
题目大意：
给定一个rotated 排序数组，元素有重复，查找某个元素是否在数组中。

解题思路：
比无重复元素的情况来讲，要多一种情况。如果nums[mid] == nums[right]，并不一定就是
不在该区间，有可能存在例如4561234这种情况。
时间复杂度：n，空间复杂度：如果计算递归深度的话，应该算是n的吧。

遇到的问题：
一定要清楚的搞清楚各种情况，不重不漏。

再次阅读：
感觉之前的解法没啥问题了。但是看了一下DISCUSS，还是有些简洁的：
class Solution {
public:
  bool search(int A[], int n, int target) {
    int lo =0, hi = n-1;
    int mid = 0;
    while(lo<hi){
          mid=(lo+hi)/2;
          if(A[mid]==target) return true;
          if(A[mid]>A[hi]){
              if(A[mid]>target && A[lo] <= target) hi = mid;
              else lo = mid + 1;
          }else if(A[mid] < A[hi]){
              if(A[mid]<target && A[hi] >= target) lo = mid + 1;
              else hi = mid;
          }else{
              hi--;
          }

    }
    return A[lo] == target ? true : false;
  }
};
又看了一下，感觉实在是精妙啊。尤其是当A[mid] == A[hi]的时候。
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)return false;
        return sub(nums, target, 0, nums.size()-1);
    }
    
    bool sub(vector<int> &nums, int target, int left, int right){
        if(right < left)return false;
        if(right - left <= 1){
            return nums[left] == target || nums[right] == target;
        }
        int mid = left + (right-left)/2;
        if(nums[mid] == target)return true;
        bool ret = false;
        if(nums[mid] < target){
            if(nums[right] > nums[mid]){
                if(nums[right] >= target){
                    ret |= sub(nums, target, mid+1, right);
                }else{
                    ret |= sub(nums, target, left, mid-1);
                }
            }else{
                ret |= sub(nums, target, left, mid-1);
                ret |= sub(nums, target, mid+1, right);
            }
        }else{
            if(nums[left] < nums[mid]){
                if(nums[left] <= target){
                    ret |= sub(nums, target, left, mid-1);
                }else{
                    ret |= sub(nums, target, mid+1, right);
                }
            }else{
                ret |= sub(nums, target, left, mid-1);
                ret |= sub(nums, target, mid+1, right);
            }
        }
        return ret;
    }
};