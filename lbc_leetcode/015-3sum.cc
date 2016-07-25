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

再次阅读：
这道题n*n的解法已经算是最优了。
DISCUSS中也是这种解法。
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
/*
第二次做：
虽然直接有了思路，但是代码还是写的不是很顺畅，应该是今天题目做的足够多了。改时间再做吧。
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;

            int left = i+1, right = nums.size()-1;
            while (left < right) {
                if (nums[left] + nums[right] == -nums[i]) {
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    ans.push_back(tmp);

                    while (left < right && nums[left+1] == nums[left]) left++;
                    left++;
                } else if (nums[left] + nums[right] < -nums[i]) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};
/*
 * 还可以
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());
        int first = 0;
        while (first+2 < nums.size()) {
            int left = first+1, right = nums.size()-1;
            while (left < right) {
                int sum = nums[left]+nums[right]+nums[first];
                if (sum == 0) {
                    vector<int> tmp(3);
                    tmp[0] = nums[first];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    ans.push_back(tmp);
                    left++;
                    while (left < right && nums[left] == nums[left-1]) left++;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }

            first++;
            while (first+2 < nums.size() && nums[first] == nums[first-1]) first++;
        }
        return ans;
    }
};
