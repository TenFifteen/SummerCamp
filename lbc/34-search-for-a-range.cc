/*
题目大意：
给一个排序的数组，其中数字有可能有重复。给定一个target，找出target的左右边界；如果没有
就是-1，-1

解题思路：
分两次分别寻找左右边界。

遇到的问题：
竟然又一次做对了。所以呢，难题并不需要畏惧，想到了各种条件，应该就没问题。
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left = 0, right = nums.size()-1;
        int ans_left = nums.size();
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                if(mid < ans_left){
                    ans_left = mid;
                }
                right = mid;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
            if(left == right && nums[left] == target){
                ans_left = left;
                break;
            }
        }
        left = 0, right = nums.size()-1;
        int ans_right = -1;
        while(left <= right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] == target){
                if(mid > ans_right){
                    ans_right = mid;
                }
                left = mid;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
            if(left == right && nums[left] == target){
                ans_right = left;
                break;
            }
        }
        if(ans_right != -1){
            ans.push_back(ans_left);
            ans.push_back(ans_right);
        }else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};