/**
 * Problem: Merge two given sorted integer array A and B into a new sorted integer array.
 * Solve: just merge
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A and B: sorted integer array A and B.
         * @return: A new sorted integer array
         */
        vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
            int m = A.size(), n = B.size();
            vector<int> ans(m+n);

            int i = 0, j = 0, pos = 0;
            while (i < m || j < n) {
                if (i < m && j < n) {
                    if (A[i] < B[j]) {
                        ans[pos++] = A[i++];
                    } else {
                        ans[pos++] = B[j++];
                    }
                } else if (i >= m) {
                    ans[pos++] = B[j++];
                } else {
                    ans[pos++] = A[i++];
                }
            }

            return ans;
        }
};
