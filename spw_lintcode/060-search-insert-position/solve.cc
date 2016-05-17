/**
 * Problem: Given a sorted array and a target value, return
 *          the index if the target is found. If not, return
 *          the index where it would be if it were inserted in order.
 *          You may assume NO duplicates in the array.
 * Solve: binary search
 * Tips: no
 */
class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
    public:
        int searchInsert(vector<int> &A, int target) {
            int left = 0, right = A.size()-1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (A[mid] == target) return mid;
                else if (A[mid] < target) left = mid+1;
                else right = mid - 1;
            }

            return left;
        }
};
