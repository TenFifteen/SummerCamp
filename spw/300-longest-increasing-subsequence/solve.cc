/**
 * Problem: Given an unsorted array of integers, find the length of longest increasing subsequence.
 * Solve: keep a increasing sequence
 * Tips: no
 */
class Solution {
    int findPos(vector<int> &seq, int target) {
        int left = 0, right = seq.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (seq[mid] == target) return mid;
            else if (seq[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        return left;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        vector<int> seq(1, nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int pos = findPos(seq, nums[i]);
            if (pos == seq.size()) seq.push_back(nums[i]);
            else seq[pos] = nums[i];
        }

        return seq.size();
    }
};
