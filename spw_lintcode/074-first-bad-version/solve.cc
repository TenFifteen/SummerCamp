/**
 * Problem: The code base version is an integer start from 1 to n. One day,
 *          someone committed a bad version in the code case, so it caused
 *          this version and the following versions are all failed in the unit
 *          tests. Find the first bad version.
 *          You can call isBadVersion to help you determine which version is the
 *          first bad one. The details interface can be found in the code's annotation part.
 * Solve: binary search.
 * Tips: update answer variable.
 */
/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
 */
class Solution {
    public:
        /**
         * @param n: An integers.
         * @return: An integer which is the first bad version.
         */
        int findFirstBadVersion(int n) {
            int left = 1, right = n;

            int ans = n;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (SVNRepo::isBadVersion(mid)) {
                    ans = min(ans, mid);
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            return ans;
        }
};

