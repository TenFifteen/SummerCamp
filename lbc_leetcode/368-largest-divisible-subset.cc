/*
 * ok.
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2) return nums;

        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> from(nums.size());
        int maxIndex = 0, maxLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            from[i] = i;
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    from[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        vector<int> ans;
        while (maxIndex != from[maxIndex]) {
            ans.push_back(nums[maxIndex]);
            maxIndex = from[maxIndex];
        }
        ans.push_back(nums[maxIndex]);

        int left = 0, right = ans.size()-1;
        while (left < right) {
            swap(ans[left++], ans[right--]);
        }
        return ans;
    }
};
