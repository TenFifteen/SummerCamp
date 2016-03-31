/**
 * Problem: Given two array of integers(the first array is array A,
 *          the second array is array B), now we are going to find
 *          a element in array A which is A[i], and another element
 *          in array B which is B[j], so that the difference between
 *          A[i] and B[j] (|A[i] - B[j]|) is as small as possible,
 *          return their smallest difference.
 * Solve: sort and find
 * Tips: fabs return double, convert it to int
 */
class Solution {
    public:
        /**
         ** @param A, B: Two integer arrays.
         ** @return: Their smallest difference.
         **/
        int smallestDifference(vector<int> &A, vector<int> &B) {
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());

            int m = A.size();
            int ans = INT_MAX;
            for (int i = 0; i < m; ++i) {

                int l = 0, r = B.size() - 1;
                while (l <= r) {
                    int mid = (l+r) >> 1;

                    if (B[mid] == A[i]) return 0;
                    else if (B[mid] < A[i]) l = mid + 1;
                    else r = mid - 1;

                }

                if (l < B.size()) ans = min(ans, (int)fabs(A[i]-B[l]));
                if (r >= 0) ans = min(ans, (int)fabs(A[i]-B[r]));

            }

            return ans;

        }

};

