/**
 * 题目：找到三个数，使得这三个数的和最接近于给定的数，返回这三个数的和。
 * 解题：和3 sum差不多，只不过这个找到了相等了就能返回，否则则需要遍历到底。
 * 注意：无
 */
class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());

            int n = nums.size();
            int ans = nums[0] + nums[1] + nums[2];
            for (int i = 0; i < n; ++i) {
                int t = target - nums[i];
                int left = i + 1, right = n - 1;
                while (left < right) {
                    int now = nums[left] + nums[right];
                    if (now == t) return target;
                    else if (now < t) {
                        if (t-now < abs(target-ans))
                            ans = now + nums[i];
                        ++left;
                    } else {
                        if (now-t < abs(target-ans))
                            ans = now + nums[i];
                        --right;
                    }
                }

                while (i+1 < n && nums[i+1] == nums[i]) ++i;
            }

            return ans;
        }
};
