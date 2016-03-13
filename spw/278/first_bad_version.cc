/**
 * Problem: 1 1 1 1 1 0 0 0 0 find the first 0.
 * Solve: binary search.
 * Tips: 1. when n is too big, it will be probably out of range.
 *       2. When left > right, then break the loop. The left
 *       will point to 0, and the right will point to 1.
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
