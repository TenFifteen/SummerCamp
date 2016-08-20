/**
 * Problem: Rob a circle houses, but you can't rob the neighbours.
 * Solve: use the solution of Rob I as a sub routine. Then we can find
 *        the max in the two cases.
 * Tips: find ideas in the discuss board.
 */
class Solution {
    public:
        int robRow(vector<int> &nums, int left, int right) {
            int pre1 = 0;
            int pre2 = 0;
            for(int i = left; i <= right; ++i) {
                if (i % 2 == 0) {
                    pre1 = max(pre1+nums[i], pre2);
                } else {
                    pre2 = max(pre2+nums[i], pre1);
                }
            }
            return max(pre1, pre2);
        }

        int rob(vector<int>& nums) {
            int n = nums.size();

            if (n == 0) return 0;
            if (n == 1) return nums[0];

            return max(robRow(nums, 0, n-2), robRow(nums, 1, n-1));
        }
};

class Solution {
public:
    int robRow(vector<int> &nums, int left, int right) {
        int it1 = 0, it2 = 0;
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            int now = max(nums[i]+it1, it2);
            ans = max(ans, now);

            it1 = it2;
            it2 = now;
        }

        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        return max(robRow(nums, 0, n-2), robRow(nums, 1, n-1));
    }
};
