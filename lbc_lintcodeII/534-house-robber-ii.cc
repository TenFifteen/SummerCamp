/*
题目大意：
抢劫房屋经典问题，有环的情况。

解题思路：
动规。

遇到的问题：
可以把空间优化掉的，懒得优化了。
*/
class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        
        vector<int> rob(n), norob(n);
        for (int i = 1; i < n; ++i) {
            rob[i] = max(rob[i-1], norob[i-1]+nums[i]);
            norob[i] = max(norob[i-1], rob[i-1]);
        }
        
        int ans = rob[n-1];
        rob[0] = nums[0];
        for (int i = 1; i < n-1; ++i) {
            rob[i] = max(rob[i-1], norob[i-1]+nums[i]);
            norob[i] = max(norob[i-1], rob[i-1]);
        }
        
        ans = max(ans, rob[n-2]);
        return ans;
    }
};
