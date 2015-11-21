/*
题目：24 % 最大间距 困难

题目大意：
给定一个无序数组。问在排序之后的数组中，相邻的元素的差值最大是多少？

解题思路：
直接排序再遍历很简单。但是是nlogn的复杂度。
用桶排序的思路来做，可以是n的复杂度。

遇到的问题：
一开始忘记了计算small和big了。直接用的0到INT_MAX
结果上来就错了。
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    struct Buck {
        int min, max;
        Buck() {
            min = max = -1;
        }
    };
    
    int maximumGap(vector<int> nums) {
        // write your code here
        if (nums.size() < 2) return 0;
        if (nums.size() == 2) return abs(nums[0] - nums[1]);
        
        int small = INT_MAX, big = -1;
        for (auto n : nums) {
            if (n < small) small = n;
            if (n > big) big = n;
        }
        
        int bucksize = (big-small+1)/nums.size();
        if (bucksize * nums.size() != big-small+1) {
            bucksize++;
        }
        vector<Buck> buckets(nums.size());
        for (auto n : nums) {
            int bucknum = (n-small) / bucksize;
            if (buckets[bucknum].min < 0) {
                buckets[bucknum].min = n;
                buckets[bucknum].max = n;
            } else {
                if (buckets[bucknum].min > n) {
                    buckets[bucknum].min = n;
                }
                if (buckets[bucknum].max < n) {
                    buckets[bucknum].max = n;
                }
            }
        }
        
        int ret = 0;
        Buck last;
        for (auto b : buckets) {
            if (b.min < 0) continue;
            if (last.min < 0) {
                last = b;
            } else {
                if (b.min - last.max > ret) {
                    ret = b.min - last.max;
                }
                last = b;
            }
        }
        
        return ret;
    }
};
