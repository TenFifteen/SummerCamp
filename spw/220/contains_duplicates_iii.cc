/**
 * Problem: Given an array of integers, find out whether there are two
 *          distinct indices i and j in the array such that the difference
 *          between nums[i] and nums[j] is at most t and the difference
 *          between i and j is at most k.
 * Solve: 1. Use set to sustain a k-size binary search tree(such that insert,
 *           find and delete are all O(lg(k)))
 * Tips: keep k elements in the set, then we should delete element when i > k
 *       because when i = k there are k elements in set
 */
class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            set<int> knums;
            for (int i = 0; i < nums.size(); ++i) {
                // i > k
                if (i > k) knums.erase(nums[i-k-1]);
                auto pos = knums.lower_bound(nums[i]-t);

                if (pos != knums.end() && *pos-nums[i] <= t) return true;
                knums.insert(nums[i]);

            }

            return false;

        }

};
