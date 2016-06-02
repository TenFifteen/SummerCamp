/**
 * Problem: Return true if there exists i, j, k
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 * Solve: use two variables to remember the two before number.
 * Tips: no
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return false;

        int one = nums[0], two = nums[0];
        for (int i = 1; i < len; ++i) {
            if (one == two) {
                if (nums[i] <= one) {
                    one = two = nums[i];
                } else {
                    two = nums[i];
                }
            } else {
                if (nums[i] > two) {
                    return true;
                } else {
                    one  = min(one, nums[i]);
                    if (nums[i] > one && nums[i] < two) {
                        two = nums[i];
                    }
                }
            }
        }

        return false;
    }
};
