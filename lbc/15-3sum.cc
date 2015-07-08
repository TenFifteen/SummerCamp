/*
题目大意：
给一个数组，找出三个数相加等于0的所有组合。但是不能重复。

解题思路：
先对整个数组排序。
然后从前往后考虑组合中的第一个数字，在第一个数字确定的情况下，使用卡尺法，从后面的一段中，
找出所有符合条件的解。
这个过程中要注意去重。

遇到的问题：
没遇到啥问题，就是开始的边界条件忘了判断了。
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() < 3)return ans;
        int last = 0;
        for(int i = 0; i < nums.size()-2; ++i){
            if(i != 0 && nums[i] == last){
                continue;
            }
            last = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                if(nums[left] + nums[right] + nums[i] == 0){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    ans.push_back(tmp);
                    while(left < right && left + 1 < nums.size() && nums[left+1] == nums[left]){
                        left++;
                    }
                    left++;
                }else if(nums[left] + nums[right] + nums[i] < 0){
                    while(left < right && left+1 < nums.size() && nums[left+1] ==nums[left]){
                        left++;
                    }
                    left++;
                }else{
                    while(right > left && right-1 > i && nums[right-1] == nums[right]){
                        right--;
                    }
                    right--;
                }
            }
        }
        return ans;
    }
};