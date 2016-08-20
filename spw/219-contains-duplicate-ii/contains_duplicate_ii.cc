/**
 * Problem: Given an array of integers and an integer k, find out whether there
 *          are two distinct indices i and j in the array such that nums[i] = nums[j]
 *          and the difference between i and j is at most k.
 * Solve: hash map
 * Tips: no
 */
class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int n = nums.size();
            if (n == 0) return false;

            unordered_map<int, int> index;
            for (int i = 0; i < n; ++i) {
                if (index.find(nums[i]) != index.end() && i-index[nums[i]] <= k)
                    return true;
                index[nums[i]] = i;

            }
            return false;

        }

};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        if (nums.size() < 2) return false;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (index.find(nums[i]) != index.end() && i-index[nums[i]] <= k) {
                return true;
            } else {
                index[nums[i]] = i;
            }
        }

        return false;
    }
};
