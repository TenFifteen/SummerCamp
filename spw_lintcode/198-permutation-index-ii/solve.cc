/**
 * Problem: Given a permutation which may contain repeated
 *          numbers, find its index in all the permutations
 *          of these numbers, which are ordered in lexicographical
 *          order. The index begins at 1.
 * Solve: the total permutation of 1 2 2 3 3 5  is 5!/(2! * 2!)
 *        Then we should divide the duplicates every time.
 * Tips: the way to calculate factorial of duplicate number
 */
class Solution {
    public:
        /**
         * @param A an integer array
         * @return a long integer
         */
        long long permutationIndexII(vector<int>& A) {

            long long fac = 1, dupFac = 1, ans = 0;
            int n = A.size();
            unordered_map<int, int> count;

            for (int i = n-1; i >= 0; --i) {
                count[A[i]]++;

                dupFac *= count[A[i]];

                int cnt = 0;
                for (int j = i+1; j < n; ++j)
                    if (A[j] < A[i])
                        cnt++;

                ans += cnt * fac / dupFac;

                fac *= n-i;
            }

            ++ans;
            return ans;
        }
};
