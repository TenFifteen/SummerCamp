/**
 * Problem: Given an integer array, find a continuous subarray where the
 *          sum of numbers is the biggest. Your code should return the
 *          index of the first number and the index of the last number.
 *          (If their are duplicate answer, return anyone)
 * Solve: sum[i] min the max sum end with arr[i]
 * Tips: initialize maxSum to INT_MIN instead of 0
 */
class Solution {
    public:
        /**
         * @param A an integer array
         * @return  A list of integers includes the index of
         *          the first number and the index of the last number
         */
        vector<int> continuousSubarraySum(vector<int>& A) {
            // Write your code here
            vector<int> ans(2, 0);
            int maxSum = INT_MIN;
            int sum = 0;

            int n = A.size();
            int s = 0;
            for (int i = 0; i < n; ++i) {
                if (sum + A[i] < A[i]) {
                    sum = A[i];
                    s = i;
                } else {
                    sum += A[i];
                }

                if (sum > maxSum) {
                    maxSum = sum;
                    ans[0] = s;
                    ans[1] = i;
                }
            }

            return ans;
        }
};
