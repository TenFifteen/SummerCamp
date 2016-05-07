/**
 * Problem: Given 2*n + 2 numbers, every numbers occurs twice except two, find them.
 * Solve: use the last bit of XOR of two different number to route the every element
 *        of array.
 * Tips: how to get the last bit 1.
 */
class Solution {
    public:
        /**
         * @param A : An integer array
         * @return : Two integers
         */
        vector<int> singleNumberIII(vector<int> &A) {
            int sum = 0;
            int n = A.size();

            for (int i = 0; i < n; ++i) {
                sum ^= A[i];
            }

            // aslo sum ^= -sum
            int flag = sum - (sum & (sum - 1));

            vector<int> ans(2, 0);
            for (int i = 0; i < n; ++i) {
                if (flag & A[i]) {
                    ans[0] ^= A[i];
                } else {
                    ans[1] ^= A[i];
                }
            }

            return ans;
        }
};
