/**
 * Problem: Given n pieces of wood with length L[i] (integer array).
 *          Cut them into small pieces to guarantee you could have
 *          equal or more than k pieces with the same length. What is
 *          the longest length you can get from the n pieces of wood?
 *          Given L & k, return the maximum length of the small pieces.
 * Solve: binary search.
 * Tips: when to update the answer.
 */
class Solution {
    public:
        /**
         *@param L: Given n pieces of wood with length L[i]
         *@param k: An integer
         *return: The maximum length of the small pieces.
         */
        int woodCut(vector<int> L, int k) {
            int cnt = 0;

            long long sum = 0;
            int n  = L.size();

            for (int i = 0; i < n; ++i) {
                sum += L[i];
            }

            int right = sum / k;
            int left = 1;

            int ans = 0;
            while (left <= right) {
                // left or mid will be too large
                int mid = left + (right - left) / 2;

                int cnt = 0;
                for (int i = 0; i < n; ++i) {
                    cnt += L[i] / mid;
                }

                if (cnt < k) {
                    right = mid - 1;
                } else {
                    // when cnt == k, we may want to
                    // find if there is a bigger cnt, then
                    // we advance the left.
                    //
                    // when cnt > k, it surely satisfy the
                    // condition, then we can update the answer
                    // use it.
                    left = mid + 1;
                    ans = max(ans, mid);
                }
            }

            return ans;

        }
};
