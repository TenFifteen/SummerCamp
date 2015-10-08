/*
题目：16 % 最接近零的子数组和 中等

题目大意：
给定一个数组，求其所有的子数组的和最接近0的一个子数组

解题思路：
跟上一个题目一样，应该是从上一个题目中获得的思路。
就是将已有的所有的0-k的子数组的和放在一个set中，然后每次查找

遇到的问题：
这个题目最大的收获应该是搞清楚了lower_bound和upper_bound还有equal_range这三个函数的含义了。
之前差不多一致都是望文生义的状态。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<int> ans(2);
        if (nums.size() == 0) return ans;
        map<long long, int> mm;
        mm[0] = -1;
        long long sum = 0;
        int last = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (mm.find(sum) != mm.end()) {
                ans[0] = mm[sum] + 1;
                ans[1] = i;
                return ans;
            } else {
                auto lower = mm.lower_bound(sum);
                if (lower != mm.end()) {
                    if (lower->first - sum < last) {
                        last = lower->first - sum;
                        ans[0] = lower->second+1;
                        ans[1] = i;
                    }
                }
                if (lower != mm.begin()) {
                    lower--;
                    if (sum - lower->first < last) {
                        last = sum - lower->first;
                        ans[0] = lower->second+1;
                        ans[1] = i;
                    }
                }
            }
            mm[sum] = i;
        }
        return ans;
    }
};

