/**
 * Problem: Given a permutation which contains no repeated number,
 *          find its index in all the permutations of these numbers,
 *          which are ordered in lexicographical order. The index begins at 1.
 * Solve: Just take 4, 2, 1 as an example. Consider every digit one by one.
 *        When consider 4, then there are (1,2)*2! before 4*2!
 *        Then consider 2, we now delete 4, then (1) * 1! before 2 * 1!
 *        ....
 * Tips: calculate from the end to the start, then the fac can increase every
 *       time by the way.
 */
class Solution {
    public:
        /**
         ** @param A an integer array
         ** @return a long integer
         **/
        long long permutationIndex(vector<int>& A) {
            int n = A.size();

            long long fac = 1, ans = 0;

            for (int i = n-1; i >= 0; --i) {
                int cnt = 0;
                for (int j = i+1; j < n; ++j)
                    if (A[j] < A[i])
                        ++cnt;

                ans += cnt * fac;
                fac *= n-i;

            }

            return ans + 1;

        }

};
