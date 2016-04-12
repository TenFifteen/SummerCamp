/**
 * Problem: Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *         You may assume no duplicate exists in the array.
 * Solve: just do it
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param num: a rotated sorted array
         * @return: the minimum number in the array
         */
        int findMin(vector<int> &num) {
            int left = 0, right = num.size() - 1;

            while (left < right) {
                int mid = (left + right) / 2;

                if (num[mid] < num[right]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            return num[left];
        }
};
