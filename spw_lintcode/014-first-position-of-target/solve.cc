/**
 * Problem: For a given sorted array (ascending order) and a target number,
 *          find the first index of this number in O(log n) time complexity.
 *          If the target number does not exist in the array, return -1.
 * Solve: just binary search & update the answer variable every time
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: The integer array.
         * @param target: Target number to find.
         * @return: The first position of target. Position starts from 0.
         */
        int binarySearch(vector<int> &array, int target) {
            int left = 0, right = array.size() - 1;

            int index = array.size();
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (array[mid] == target) {
                    index = min(index, mid);
                    right = mid - 1;
                } else if (array[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            return index == array.size() ? -1 : index;
        }
};
