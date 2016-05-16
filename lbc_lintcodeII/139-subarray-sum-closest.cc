/*
题目大意：
给定一个数组，求子数组和最小
解题思路：
求偏序和，然后排序。

遇到的问题：
一开始忘记了处理下标+1的情况
后来是忘记了处理区间从0开始的情况。
而且最开始还忘记了溢出的情况。。
反正就是各种错误基本都除了。
甚至方法也不是自己想出来的，我一开始想的是用一个set来存放
前面已经处理的偏序和，但是需要两个set，用两次lower_bound。
不过复杂度倒是都一样，还是人家这个思路简单一些。
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
        vector<int> ans(2, -1);
        if (nums.size() == 0) return ans;
        
        vector<pair<long long, int>> sum(nums.size());
        sum[0] = make_pair(nums[0], 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum[i].first = sum[i-1].first + nums[i];
            sum[i].second = i;
        }
        
        long long minSub = LONG_LONG_MAX; //overflows if INT_MAX
        for (int i = 0; i < nums.size(); ++i) {
            if (abs(nums[i]) < minSub) {
                minSub = abs(nums[i]);
                ans[0] = ans[1] = i;
            }
            if (abs(sum[i].first) < minSub) {
                ans[0] = 0;
                ans[1] = sum[i].second;
            }
        }
        
        sort(sum.begin(), sum.end());
        for (int i = 0; i+1 < sum.size(); ++i) {
            long long cur = sum[i+1].first;
            cur -= sum[i].first;
            if (cur < minSub) {
                minSub = cur;
                if (sum[i+1].second > sum[i].second) {
                    ans[1] = sum[i+1].second;
                    ans[0] = sum[i].second+1;
                } else {
                    ans[1] = sum[i].second;
                    ans[0] = sum[i+1].second+1;
                }
            }
        }
        
        return ans;
    }
};
