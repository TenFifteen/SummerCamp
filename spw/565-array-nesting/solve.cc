/**
 * Problem: A zero-indexed array A consisting of N different integers
 *          is given. The array contains all integers in the range [0, N - 1].
 *
 *          Sets S[K] for 0 <= K < N are defined as follows:
 *
 *          S[K] = { A[K], A[A[K]], A[A[A[K]]], ...  }.
 *
 *          Sets S[K] are finite for each K and should NOT contain duplicates.
 *          Write a function that given an array A consisting of N integers,
 *          return the size of the largest set S[K] for this array.
 * Solve: All the numbers can form some circles. No one will be left.
 * Tips: count
 */
class Solution {
    public:
        int arrayNesting(vector<int>& nums) {
            int n = nums.size();
            vector<bool> visited(n, false);
            int len = 0;

            for (int i = 0; i < n; ++i) {
                if (visited[i]) continue;

                int startPos = i, next = nums[i], cnt = 1;

                visited[startPos] = true;
                while (next != startPos) {
                    visited[next] = true;
                    next = nums[next];
                    ++cnt;
                }

                len = max(cnt, len);
            }

            return len;
        }
};
