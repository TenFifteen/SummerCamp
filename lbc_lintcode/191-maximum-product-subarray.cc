/*
题目：28 % 乘积最大子序列 中等

题目大意：
给定一个数组，问最大的子数组乘积和是多少？

解题思路：
动归

遇到的问题：
一开始弄复杂了，先是空间超时，然后是时间超时，第三次才弄好。
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        vector<int> big(nums.size()), small(nums.size());
        int ret = nums[0];
        big[0] = small[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            big[i] = max(small[i-1] * nums[i], big[i-1] *nums[i]);
            big[i] = max(big[i], nums[i]);
            small[i] = min(small[i-1] * nums[i], big[i-1] * nums[i]);
            small[i] = min(small[i], nums[i]);
            
            if (big[i] > ret) {
                ret = big[i];
            }
        }
        return ret;
    }
    
    int maxProduct3(vector<int>& nums) {
        // write your code here
        int ret = nums[0];
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = nums[i];
            if (dp[i] > ret) {
                ret = dp[i];
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size()-i; ++j) {
                dp[j] = dp[j+1] * nums[j];
                if (dp[j] > ret) {
                    ret = dp[j];
                }
            }
        }
        return ret;
    }

    int maxProduct2(vector<int>& nums) {
        // write your code here
        int ret = nums[0];
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        for (int i = 0; i < nums.size(); ++i) {
            dp[i][0] = nums[i];
            if (dp[i][0] > ret) {
                ret = dp[i][0];
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size()-i; ++j) {
                dp[j][i] = dp[j][i-1] * nums[j+i];
                if (dp[j][i] > ret) {
                    ret = dp[j][i];
                }
            }
        }
        return ret;
    }
};
