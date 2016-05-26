/*
题目大意：
给定一个数组，求其连续的最大的子数组的乘积。

解题思路：
用动态规划，以当前元素为结尾的子数组的最大乘积等于max（last_max*nums[i],
last_min*nums[i], nums[i])

遇到的问题：
一开始用的二维的动归，超时。
感觉并没有想清楚这个题目，所以看了网上别人的解法，才感觉豁然开朗。

再次阅读：
一开始感觉这道题还挺麻烦的，但是看了之前的代码之后，感觉之前的想法简直是厉害呀。
这个题目值得好好的学习一下动态规划的思想了。
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0];
        int last_max = nums[0];
        int last_min = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int cur_max = max(max(last_max*nums[i], last_min*nums[i]), nums[i]);
            int cur_min = min(min(last_max*nums[i], last_min*nums[i]), nums[i]);
            if(cur_max > ret)ret = cur_max;
            last_max = cur_max;
            last_min = cur_min;
        }
        return ret;
    }
};
/*
第二次做：
虽然做对了，但是那个n的空间完全可以省掉的。
另外一点注意的是，如果我们自己定义了一个跟std中重名的函数的话，搜索范围就只限制到了当前class内部了。
*/
class Solution {
private:
    int Max(int a, int b, int c) {
        return max(a, max(b, c));
    }
    
    int Min(int a, int b, int c) {
        return min(a, min(b, c));
    }

public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int n = nums.size(), ans = nums[0];
        vector<int> dmax(n), dmin(n);
        dmax[0] = dmin[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            dmax[i] = Max(nums[i], nums[i]*dmax[i-1], nums[i]*dmin[i-1]);
            dmin[i] = Min(nums[i], nums[i]*dmax[i-1], nums[i]*dmin[i-1]);
            ans = max(ans, dmax[i]);
        }
        
        return ans;
    }
};