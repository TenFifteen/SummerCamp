/**
 * Problem: Given an integers array A.
 *          Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1],
 *          calculate B WITHOUT divide operation.
 * Solve: one pass, calculate two side of two number
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A: Given an integers array A
         * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
         */
        vector<long long> productExcludeItself(vector<int> &nums) {
            long long lp = 1, rp = 1;

            int n = nums.size();
            vector<long long> ans(n, 1);
            for (int i = 0; i < n; ++i) {
                ans[i] *= lp;
                ans[n-i-1] *= rp;

                lp *= nums[i];
                rp *= nums[n-i-1];
            }

            return ans;
        }
};
