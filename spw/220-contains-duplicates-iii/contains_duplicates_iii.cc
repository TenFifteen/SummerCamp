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

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0 || k <= 0) return false;

        // the latter must be long long
        // or the nums[i]-bucket[pos-1] may be out of int range.
        unordered_map<long long, long long> bucket;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            long long pos = ((long long)nums[i] - INT_MIN) / ((long long)t + 1);
            if (bucket.find(pos) != bucket.end()
                || bucket.find(pos-1) != bucket.end() && nums[i] - bucket[pos-1] <= t
                || bucket.find(pos+1) != bucket.end() && bucket[pos+1] - nums[i] <= t)
                return true;

            bucket[pos] = nums[i];
            if (i >= k) {
                // must convert nums[i-k] to long long first or it will be overflow
                long long rmPos = ((long long)nums[i-k] - INT_MIN) / (t+1);
                bucket.erase(rmPos);
            }
        }

        return false;
    }
};
