/*
题目：26 % 主元素 II 中等

题目大意：
给定一个数组，其中有一个元素的数量超过了全部元素数量的三分之一，找出该元素

解题思路：
二分

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        auto ret = sub(nums, 0, nums.size()-1);
        return ret[0];
    }
    
    vector<int> sub(vector<int> &nums, int left, int right) {
        vector<int> ret;
        if (left > right) return ret;
        if (left == right) {
            ret.push_back(nums[left]);
            return ret;
        } else if (left + 1 == right) {
            ret.push_back(nums[left]);
            if (nums[right] != nums[left]) {
                ret.push_back(nums[right]);
            }
            return ret;
        }
        int mid = left + (right-left+1)/2;
        auto ret_l = sub(nums, left, mid-1);
        auto ret_r = sub(nums, mid, right);
        unordered_set<int> visited;
        for (auto r : ret_l) {
            visited.insert(r);
            if (count(nums, left, right, r) > (right-left+1)/3) {
                ret.push_back(r);
            }
        }
        for (auto r : ret_r) {
            if (visited.find(r) != visited.end()) continue;
            if (count(nums, left, right, r) > (right-left+1)/3) {
                ret.push_back(r);
            }
        }
        return ret;
    }
    
    int count(vector<int> &nums, int left, int right, int val) {
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            if (nums[i] == val) ret++;
        }
        return ret;
    }
};

