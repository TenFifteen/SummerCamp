/**
 * Problem: There is an integer array which has the following features:
 *          The numbers in adjacent positions are different.
 *          A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
 *          We define a position P is a peek if:
 *          A[P] > A[P-1] && A[P] > A[P+1]
 *          Find a peak element in this array. Return the index of the peak.
 * Solve: the additional condition is to make us use binary search.
 * Tips: boundary.
 */
class Solution {
    public:
        /**
         * @param A: An integers array.
         * @return: return any of peek positions.
         */
        int findPeak(vector<int> A) {
            int n = A.size();
            int left = 0, right = A.size()-1;

            int ans = 0;
            while (left < right) {
                int mid = left + (right - left) / 2;

                if (mid > 0 && A[mid-1] > A[mid]) {
                    right = mid - 1;
                } else if (mid < n-1 && A[mid+1] > A[mid]) {
                    left = mid + 1;
                } else {
                    // just return
                    return mid;
                }
            }
        }
};
