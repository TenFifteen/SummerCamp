/**
 * Problem: Given a sorted array and a target value, return the index if
 *          the target is found. If not, return the index where it would
 *          be if it were inserted in order. You may assume no duplicates in the array.
 * Solve: binary search and when stop left > right, the number should insert
 *        between position right and left
 * Tips: no
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }
};
