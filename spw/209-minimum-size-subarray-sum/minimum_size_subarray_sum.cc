/**
 * Problem: Given an array of n positive integers and a
 *          positive integer s, find the minimal length
 *          of a subarray of which the sum ≥ s. If there i
 *          sn't one, return 0 instead.
 * Solve: accumulate and binary search.
 * Tips: 1. Watching out for the index.
 */
class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return 0;

            vector<int> acc(n+1, 0);
            for (int i = 0; i < n; ++i) {
                acc[i+1] = acc[i] + nums[i];
            }
            if (acc[n] < s) return 0;

            int ans = INT_MAX;
            int i = n;
            while (i > 0 && acc[i] >= s) {
                int left = 0;
                int right = i-1;
                int t = acc[i] - s;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (acc[mid] < t) {
                        left = mid + 1;
                    } else if (acc[mid] > t) {
                        right = mid - 1;
                    } else {
                        ans = min(ans, i-mid);
                        break;
                    }
                }
                if (left > right)
                    ans = min(ans, i-right);
                --i;
            }

            return ans;
        }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        vector<int> numsSum(n+1, 0);

        for (int i = 0; i < n; ++i)
            numsSum[i+1] = numsSum[i] + nums[i];
        if (numsSum[n] < s) return 0;

        int i = 0, j = 1;
        int ans = n;
        while (j <= n) {
            if (numsSum[j] - numsSum[i] < s) {
                ++j;
            } else {
                ans = min(j-i, ans);
                ++i;
            }
        }

        return ans;
    }
};
